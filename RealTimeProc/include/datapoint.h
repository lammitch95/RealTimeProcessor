#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <QString>


class DataPoint
{

public:
    DataPoint(double a,double b, const QString sType);
    ~DataPoint();

    double getXData() const{
        return xData;
    }

    double getYData() const{
        return yData;
    }

    QString getSensorType() const{
        return sensorType;
    }

private:
    double xData;
    double yData;
    QString sensorType;

};

#endif // DATAPOINT_H
