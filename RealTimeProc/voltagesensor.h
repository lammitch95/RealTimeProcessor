#ifndef VOLTAGESENSOR_H
#define VOLTAGESENSOR_H

#include "sensorsimulator.h"
#include <QObject>


using namespace std;

class VoltageSensor: public SensorSimulator{

    Q_OBJECT

public:
    explicit VoltageSensor(QObject *parent = nullptr);
    ~VoltageSensor();
    double generatedData() override;
};

#endif // VOLTAGESENSOR_H
