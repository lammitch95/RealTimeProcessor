#include "pressuresensor.h"

#include <cmath>
//#include <iomanip>
//#include <sstream>

using namespace std;

PressureSensor::PressureSensor(QObject *parent)
    : SensorSimulator("Pressure",generatedData(),"Pa",parent)  {}

double PressureSensor::generatedData(){

    //rememberGenerate random pressure between 1000 and 1100 Pascals
    double randPressure = (rand() % 101) + 1000;
    randPressure = round(randPressure * 10) / 10;
    //stringstream ss;
    //ss << fixed << setprecision(1) << randPressure;

    return randPressure;

}
