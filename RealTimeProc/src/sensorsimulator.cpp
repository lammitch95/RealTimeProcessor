#include "sensorsimulator.h"

int SensorSimulator::temperatureIDCounter = 0;
int SensorSimulator::pressureIDCounter = 0;
int SensorSimulator::voltageIDCounter = 0;

SensorSimulator::SensorSimulator(const QString &type, const double &data, const QString &uom, QObject *parent)
    : QObject(parent), sensorType(type), sensorData(data), sensorUOM(uom){

    if(type == "Temperature"){
        sensorID = temperatureIDCounter++;
    }else if(type == "Voltage"){
        sensorID = voltageIDCounter++;
    }else if(type == "Pressure"){
        sensorID = pressureIDCounter++;
    }

};

SensorSimulator::~SensorSimulator(){};

int SensorSimulator::getSensorID() const {return sensorID;}
QString SensorSimulator::getSensorType() const {return sensorType;}
double SensorSimulator::getSensorData() const {return sensorData;}
QString SensorSimulator::getSensorUOM() const{return sensorUOM;}

