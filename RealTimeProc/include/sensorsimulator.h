#ifndef SENSORSIMULATOR_H
#define SENSORSIMULATOR_H

#include <QObject>
#include <QString>


using namespace std;

class SensorSimulator: public QObject{

    Q_OBJECT

public:
    explicit SensorSimulator(const QString &type, const double &data, const QString &uom, QObject *parent = nullptr);
    virtual~SensorSimulator();

    int getSensorID() const;
    QString getSensorType() const;
    double getSensorData() const;
    QString getSensorUOM() const;

    virtual double generatedData() = 0;

signals:
    void newData(int sensorID, const QString &sensorType, const double &sensorData, const QString &sensorUOM);

private:
        int sensorID;
        QString sensorType;
        double sensorData;
        QString sensorUOM; //Unit of Measurement
        static int temperatureIDCounter;
        static int pressureIDCounter;
        static int voltageIDCounter;

};


#endif // SENSORSIMULATOR_H
