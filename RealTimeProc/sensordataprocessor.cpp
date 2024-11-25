#include "sensordataprocessor.h"
#include "temperaturesensor.h"
#include "pressuresensor.h"
#include "voltagesensor.h"

#include <cmath>
#include <QRandomGenerator>
#include <QDebug>
#include <QElapsedTimer>

SensorDataProcessor::SensorDataProcessor(QObject *parent): QObject(parent), isProcessing(false) {}
SensorDataProcessor::~SensorDataProcessor(){}

void SensorDataProcessor::startProcessing(int numDataPoints){

    if(isProcessing){
        emit statusChanged("Already processing");
        return;
    }

    isProcessing = true;
    processCounter = 0;

    emit statusChanged("Starting data processing...");

    std::thread([this, numDataPoints]() {
        generateSensors(numDataPoints);
        processData();
        isProcessing = false;
        emit statusChanged("Processing complete.");
    }).detach();
}

void SensorDataProcessor::stopProcessing(){
    if (!isProcessing) {
        emit statusChanged("No processing to stop.");
        return;
    }

    isProcessing = false;
    emit statusChanged("Processing stopped.");
}

void SensorDataProcessor::resetProcess(){

    stopProcessing();
    rawData.clear();

    processCounter = 0;

    minTemp = minPressure = minVoltage = 1e9;
    maxTemp = maxPressure = maxVoltage = -1e9;
    totalTemp = totalPressure = totalVoltage = 0;
    tempCount = pressureCount = voltageCount = 0;

    emit statusChanged("Processor reset.");
    emit progressUpdated(QString("Restart..."),0, 0);
    emit statsUpdated("Temperature", 0.0, 0.0, 0.0);
    emit statsUpdated("Pressure", 0.0, 0.0, 0.0);
    emit statsUpdated("Voltage", 0.0, 0.0, 0.0);
}

void SensorDataProcessor::updateStats(double value, double &min, double &max, double &sum, int &count) {
    if (value < min) min = value;
    if (value > max) max = value;
    sum += value;
    ++count;
}

void SensorDataProcessor::processData(){
    if(rawData.empty())return;

    // Divide data into chunks based on number of available CPU cores
    int chunkSize = rawData.size() / std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    processCounter = 0;

    const int updateInterval = 10000;

    emit statusChanged("(Multi Thread) Processing Data Objects...");

    QElapsedTimer processTimer;
    processTimer.start();

    for(size_t i = 0; i < std::thread::hardware_concurrency(); ++i){
        int startIndex = i * chunkSize;
        int endIndex = (i == std::thread::hardware_concurrency() - 1) ? rawData.size() : (i + 1) * chunkSize;

        threads.push_back(std::thread([this,startIndex,endIndex, &processTimer](){

            int localProgress = 0;
            QList<DataPoint> localDataList;

            for(int j = startIndex; j < endIndex; ++j){
                 if (!isProcessing) return;

                 int sensorID = rawData[j]->getSensorID();
                 double sensorData = rawData[j]->getSensorData();
                 QString sensorType = rawData[j]->getSensorType();

                 double elapsedTime = processTimer.elapsed() / 1000.0;

                 if (sensorType == "Temperature") {

                     updateStats(sensorData, minTemp, maxTemp, totalTemp, tempCount);

                 } else if (sensorType == "Pressure") {

                     updateStats(sensorData, minPressure, maxPressure, totalPressure, pressureCount);

                 } else if (sensorType == "Voltage") {

                     updateStats(sensorData, minVoltage, maxVoltage, totalVoltage, voltageCount);
                 }

                 localDataList.append(DataPoint(sensorID, elapsedTime,sensorType));

                localProgress++;

                if (localProgress % updateInterval == 0 || j == endIndex - 1) {
                    
                    processCounter += localProgress;

                    emit progressUpdated(QString("Processing Data Objects..."),processCounter, rawData.size());
                    emit statsUpdated("Temperature", totalTemp/tempCount, minTemp, maxTemp);
                    emit statsUpdated("Pressure", totalPressure/pressureCount, minPressure, maxPressure);
                    emit statsUpdated("Voltage", totalVoltage/voltageCount, minVoltage, maxVoltage);

                    emit updateCharts("update", localDataList);
                    localDataList.clear();

                    localProgress = 0;
                }


            }
        }));

    }

    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }


}


void SensorDataProcessor::generateSensors(int numDataPoints){

    rawData.clear();

    processCounter = 0;

    const int updateInterval = 10000;

    int localProgress = 0;

    emit statusChanged("(Single Thread) Generating Data Objects...");


    for(int i = 0; i < numDataPoints; ++i){

        if(!isProcessing)return;

        std::unique_ptr<SensorSimulator> sensor;

        int randNum = QRandomGenerator::global()->bounded(1, 4); //1-3

        switch(randNum){
        case 1:
            sensor = std::make_unique<TemperatureSensor>();
            break;
        case 2:
            sensor = std::make_unique<PressureSensor>();
            break;
        case 3:
            sensor = std::make_unique<VoltageSensor>();
            break;
        }

        if(sensor){
            rawData.push_back(std::move(sensor));

            localProgress++;

            if (localProgress % updateInterval == 0 ) {

                processCounter += localProgress;


                emit progressUpdated("Generating Data Objects...",processCounter, numDataPoints);

                localProgress = 0;
            }

        }
    }

     emit progressUpdated("Generating Data Objects...",numDataPoints, numDataPoints);
}
