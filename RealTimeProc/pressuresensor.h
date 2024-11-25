#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

#include "sensorsimulator.h"
#include <QObject>

using namespace std;

class PressureSensor : public SensorSimulator{

    Q_OBJECT

public:
    explicit PressureSensor(QObject *parent = nullptr);
    double generatedData() override;
};

#endif // PRESSURESENSOR_H
