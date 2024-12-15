#include "sensordataprocessor.h"
#include "temperaturesensor.h"
#include "pressuresensor.h"
#include "voltagesensor.h"

#include <cmath>
#include <QRandomGenerator>
#include <QDebug>
#include <QDateTime>

SensorDataProcessor::SensorDataProcessor(QObject *parent): QObject(parent), isProcessing(false) {}
SensorDataProcessor::~SensorDataProcessor(){}

void SensorDataProcessor::startProcessing(int numDataPoints){

    if(isProcessing){
        emit statusChanged("Already processing");
        return;
    }

    isProcessing = true;
    processCounter = 0;
    activeTask = 0;

    emit statusChanged("Starting data processing...");

    pool = new ThreadPool(std::thread::hardware_concurrency());

 /*
     std::thread([this, numDataPoints]() {
        generateSensors(numDataPoints);
        processData();
    }).detach();
*/

    pool->addTask([this, numDataPoints]() {
        generateSensors(numDataPoints);
         processData();
    });

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

    startGenObjTime = 0.0;
    startProcObjTime = 0.0;
    generateObjectTime = 0.0;
    processObjectTime = 0.0;

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

void SensorDataProcessor::processDataChunk(int startIndex, int endIndex,  qint64 startTime, int updateInterval){

    int localProgress = 0;
    QList<DataPoint> localDataList;

    for(int j = startIndex; j < endIndex; ++j){
        if (j < 0 || j >= rawData.size()) {
            qWarning() << "Index out of bounds for rawData:" << j;
            continue;
        }

        int sensorID = rawData[j]->getSensorID();
        double sensorData = rawData[j]->getSensorData();
        QString sensorType = rawData[j]->getSensorType();

        qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
        double elapsedTime = currentTime - startTime;

        //qDebug() << "Elapsed process time: " << elapsedTime;

        if (sensorType == "Temperature") {
             updateStats(sensorData, minTemp, maxTemp, totalTemp, tempCount);
        } else if (sensorType == "Pressure") {
             updateStats(sensorData, minPressure, maxPressure, totalPressure, pressureCount);
        } else if (sensorType == "Voltage") {
            updateStats(sensorData, minVoltage, maxVoltage, totalVoltage, voltageCount);
        }

        localDataList.append(DataPoint(sensorID, elapsedTime,sensorType));

        localProgress++;

        bool isFinalUpdate = (j == endIndex - 1);
        if (localProgress % updateInterval == 0 || isFinalUpdate) {

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

}

void SensorDataProcessor::processData(){
    if(rawData.empty())return;

    int rawDataSize = rawData.size();
    int chunkSize = rawDataSize / std::thread::hardware_concurrency();

    processCounter = 0;

    const int updateInterval = std::max(1000, rawDataSize / 100);

    emit statusChanged("(Multi Thread) Processing Data Objects...");

    qint64 startTime = QDateTime::currentMSecsSinceEpoch();
    startProcObjTime = startTime;

    activeTask = std::thread::hardware_concurrency();
    qDebug() << "Starting tasks remaining:" << activeTask;

    for(size_t i = 0; i < std::thread::hardware_concurrency(); ++i){
        int startIndex = i * chunkSize;
        int endIndex = (i == std::thread::hardware_concurrency() - 1) ? rawData.size() : (i + 1) * chunkSize;

        pool->addTask([this,startIndex,endIndex,startTime, updateInterval]{
            try {
                processDataChunk(startIndex, endIndex, startTime, updateInterval);

                {
                    std::lock_guard<std::mutex> lock(activeTaskMutex);
                    --activeTask;
                    qDebug() << "Active tasks remaining:" << activeTask;
                }

                if (activeTask == 0) {
                    isProcessing = false;

                    qint64 tempTime =  QDateTime::currentMSecsSinceEpoch();
                    processObjectTime = tempTime - startProcObjTime;
                    emit updateProcessTime(generateObjectTime, processObjectTime);
                    emit statusChanged("Processing complete.");
                    emit updateCharts("update");



                    static bool poolCleaned = false;

                    if (pool && !poolCleaned) {
                        poolCleaned = true;
                        QMetaObject::invokeMethod(this, [this]() {
                            delete pool;
                            pool = nullptr;
                            qDebug() << "ThreadPool Deconstructor called!!";
                        }, Qt::QueuedConnection);
                    }

                }

            } catch (const std::exception &e) {
                qCritical() << "Error in processing data chunk:" << e.what();
            }

        });
    }

}


void SensorDataProcessor::generateSensors(int numDataPoints){

    rawData.clear();

    processCounter = 0;

    const int updateInterval = 10000;

    int localProgress = 0;

    emit statusChanged("(Single Thread) Generating Data Objects...");

    startGenObjTime = QDateTime::currentMSecsSinceEpoch();

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
     qint64 tempEndTime = QDateTime::currentMSecsSinceEpoch();
     generateObjectTime = tempEndTime - startGenObjTime;

}
