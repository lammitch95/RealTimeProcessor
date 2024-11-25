#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "sensorsimulator.h"
#include <QObject>


class TemperatureSensor : public SensorSimulator{

    Q_OBJECT

public:
    explicit TemperatureSensor(QObject *parent = nullptr);
    double generatedData() override;
};

#endif // TEMPERATURESENSOR_H
