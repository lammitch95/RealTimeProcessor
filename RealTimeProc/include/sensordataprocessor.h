#ifndef SENSORDATAPROCESSOR_H
#define SENSORDATAPROCESSOR_H

#include <QObject>
#include <QThread>
#include <QList>
#include <atomic>
#include <sensorsimulator.h>
#include <datapoint.h>

#include "threadpool.h"

using namespace std;


class SensorDataProcessor: public QObject{

    Q_OBJECT

public:
    explicit SensorDataProcessor(QObject *parent = nullptr);
    ~SensorDataProcessor();

    void startProcessing(int numDataPoints);
    void stopProcessing();
    void resetProcess();

signals:
    void progressUpdated(const QString &statusMessage,int current, int total);
    void statusChanged(const QString &status);
    void statsUpdated(const QString &sensorType, double dataAverage, double dataMin, double dataMax);
    void updateCharts(const QString &status, const QList<DataPoint> dataPoints = QList<DataPoint>());
    void updateProcessTime(const double &timeOne, const double &timeTwo);

private:

    void generateSensors(int numDataPoints);
    void processData();
    void processDataChunk(int startIndex, int endIndex, qint64 startTime, int updateInterval);
    void updateStats(double value, double &min, double &max, double &sum, int &count);

    int totalDataPoints = 0;
    vector<unique_ptr<SensorSimulator>> rawData;
    atomic<bool> isProcessing = false;
    atomic<int> processCounter = 0;
    double generateObjectTime = 0.0, processObjectTime = 0.0;
    qint64 startGenObjTime = 0.0, startProcObjTime = 0.0;
    mutex dataMutex;
    mutex activeTaskMutex;

    ThreadPool *pool = nullptr;

    double totalTemp = 0.0, totalPressure = 0.0, totalVoltage = 0.0;
    double minTemp = 1e9, minPressure = 1e9, minVoltage = 1e9;
    double maxTemp = -1e9, maxPressure = -1e9, maxVoltage = -1e9;
    int tempCount = 0, pressureCount = 0, voltageCount = 0, activeTask = 0;

};

#endif // SENSORDATAPROCESSOR_H
