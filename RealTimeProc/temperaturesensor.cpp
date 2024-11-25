#include "temperaturesensor.h"

#include <cmath>
//#include <iomanip>
//#include <sstream>
#include <QString>

using namespace std;

TemperatureSensor::TemperatureSensor(QObject *parent)
    :SensorSimulator("Temperature",generatedData(),"Celsius",parent){};

double TemperatureSensor::generatedData(){

    //remember random temperature between 20 and 120 degrees Celsius
    double randDegrees = (rand() % 101) + 20.0;
    randDegrees = round(randDegrees * 10) / 10;
    //stringstream ss;
    //ss << fixed << setprecision(1) << randDegrees;
    // "\xB0" is °
    return randDegrees;
}

