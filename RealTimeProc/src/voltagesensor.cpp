#include "voltagesensor.h"

#include <cmath>
//#include <iomanip>
//#include <sstream>

using namespace std;

VoltageSensor::VoltageSensor(QObject *parent)
    :SensorSimulator("Voltage",generatedData(), "V", parent){};

VoltageSensor::~VoltageSensor(){}

double VoltageSensor::generatedData(){

    //remember Generate random voltage between 3 and 23 Volts
    double randVoltage = (rand() % 21) + 3;
    randVoltage = round(randVoltage * 10) / 10;
    return randVoltage;
}
