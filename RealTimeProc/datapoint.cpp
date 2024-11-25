#include "datapoint.h"

DataPoint::DataPoint(double a, double b, const QString sType): xData(a), yData(b),sensorType(sType) {}
DataPoint::~DataPoint(){}
