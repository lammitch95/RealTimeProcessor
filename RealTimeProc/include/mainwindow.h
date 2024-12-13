#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sensordataprocessor.h>
#include <datapoint.h>
#include <QVBoxLayout>


#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QScatterSeries>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStart_clicked();
    void on_btnReset_clicked();

    void updateProgress(const QString &progressMess,int current, int total);
    void updateStatus(const QString &status);
    void statsUpdated(const QString &sensorType, double dataAverage, double dataMin, double dataMax);
    void updateCharts(const QString &status, const QList<DataPoint> &dataPoints);


    void on_BtnTempChart_clicked();

    void on_BtnPressChart_clicked();

    void on_BtnVoltageChart_clicked();

private:
    Ui::MainWindow *ui;
    SensorDataProcessor *processor;

    QChart *mainChart;
    QChartView *mainChartView;
    QString currentSensorType;
    QScatterSeries *currentSeries;
    QMap<QString, QLineSeries*> series;

    QList<DataPoint> temperatureDataPoints;
    QList<DataPoint> pressureDataPoints;
    QList<DataPoint> voltageDataPoints;

    void refreshChart(const QList<DataPoint> &data, const QString &title);
    QList<DataPoint> aggregateData(const QList<DataPoint> &data);
};
#endif // MAINWINDOW_H
