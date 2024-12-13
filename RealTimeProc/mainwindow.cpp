#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datapoint.h"
#include <QMessageBox>
#include <QString>
#include <QList>
#include <QScatterSeries>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , processor(new SensorDataProcessor(this))
{
    ui->setupUi(this);

    connect(processor, &SensorDataProcessor::progressUpdated, this, &MainWindow::updateProgress, Qt::QueuedConnection);
    connect(processor, &SensorDataProcessor::statusChanged, this, &MainWindow::updateStatus, Qt::QueuedConnection);
    connect(processor, &SensorDataProcessor::statsUpdated, this, &MainWindow::statsUpdated, Qt::QueuedConnection);
    connect(processor, &SensorDataProcessor::updateCharts, this, &MainWindow::updateCharts, Qt::QueuedConnection);


    ui->LBLProcess->setText(QString("NA...(0/0)"));
    ui->LblStatus->setText(QString("Status: None"));

    temperatureDataPoints = QList<DataPoint>();
    pressureDataPoints = QList<DataPoint>();
    voltageDataPoints = QList<DataPoint>();

    updateCharts("initial", temperatureDataPoints);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked()
{
    bool validNum;
    int numPoints = ui->SensorAmountTxt->text().toInt(&validNum);

    if(validNum and numPoints > 0){

        processor->startProcessing(numPoints);

        ui->btnStart->setEnabled(false);
        ui->btnReset->setEnabled(true);
    }else{
         QMessageBox::warning(this, "Invalid Input", "Please enter a valid number of data points greater than 0.");
    }

}


void MainWindow::on_btnReset_clicked()
{

    processor->resetProcess();

    ui->btnStart->setEnabled(true);
    ui->btnReset->setEnabled(false);

}


void MainWindow::updateProgress(const QString &progresMess, int current, int total){
    ui->LBLProcess->setText(QString("%1%2/%3").arg(progresMess).arg(current).arg(total));
}

void MainWindow::updateStatus(const QString &status){
    ui->LblStatus->setText(QString("Status: %1").arg(status));
}

void MainWindow::statsUpdated(const QString &sensorType, double dataAverage, double dataMin, double dataMax){

    int row = 0;
    QString selectedUOM = "";

    if(sensorType == "Temperature"){
        row = 0;
        selectedUOM = "Celsius";
    }else if(sensorType == "Pressure"){
        row = 1;
        selectedUOM = "Pa";

    }else if(sensorType == "Voltage"){
        row = 2;
        selectedUOM = "V";
    }

    ui->SensorTable->setItem(row,0, new QTableWidgetItem(QString("%1 %2").arg(dataAverage,0,'f',2).arg(selectedUOM))); //Average
    ui->SensorTable->setItem(row,1, new QTableWidgetItem(QString("%1 %2").arg(dataMin,0,'f',2).arg(selectedUOM))); //Min
    ui->SensorTable->setItem(row,2, new QTableWidgetItem(QString("%1 %2").arg(dataMax,0,'f',2).arg(selectedUOM))); //Max
}



void MainWindow::updateCharts(const QString &status, const QList<DataPoint> &dataPoints){

    if(status == "initial"){
        mainChart = new QChart();
        mainChart->setTitle("Sensor Data");

        mainChartView = new QChartView(mainChart);
        mainChartView->setRenderHint(QPainter::Antialiasing);
        mainChartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        ui->chartHolder->addWidget(mainChartView);

        ui->chartHolder->layout()->update();

        currentSeries = new QScatterSeries();
        mainChart->addSeries(currentSeries);

        QValueAxis *axisX = new QValueAxis();
        axisX->setTitleText("Object ID");
        //axisX->setRange(0, 10);
        mainChart->addAxis(axisX, Qt::AlignBottom);
        currentSeries->attachAxis(axisX);

        QValueAxis *axisY = new QValueAxis();
        axisY->setTitleText("Processing Tims (s)");
        axisY->setRange(0, 10);
        mainChart->addAxis(axisY, Qt::AlignLeft);
        currentSeries->attachAxis(axisY);

    }else if(status == "update"){

      //qDebug() << "local data list:" << dataPoints.size();

        for (const auto &point : dataPoints) {
            QString type = point.getSensorType();
            if (type == "Temperature") {
                temperatureDataPoints.append(point);
            } else if (type == "Pressure") {
                pressureDataPoints.append(point);
            } else if (type == "Voltage") {
                voltageDataPoints.append(point);
            }
        }

        // Update the currently displayed chart
        if (currentSensorType == "Temperature") {
            refreshChart(temperatureDataPoints, "Temperature");
        } else if (currentSensorType == "Pressure") {
            refreshChart(pressureDataPoints, "Pressure");
        } else if (currentSensorType == "Voltage") {
            refreshChart(voltageDataPoints, "Voltage");
        }
    }
}

QList<DataPoint> downsampleData(const QList<DataPoint> &data, int maxPoints) {
    if (data.size() <= maxPoints)
        return data;

    QList<DataPoint> sampledData;
    int step = data.size() / maxPoints;
    for (int i = 0; i < data.size(); i += step) {
        sampledData.append(data[i]);
    }
    return sampledData;
}


void MainWindow::refreshChart(const QList<DataPoint> &data, const QString &title){
    if (currentSeries) {
        mainChart->removeSeries(currentSeries);
        currentSeries->clear();
    }

    QList<DataPoint> sampledData = downsampleData(data, 10000);

    QScatterSeries *scatterSeries = new QScatterSeries();
    scatterSeries->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    scatterSeries->setMarkerSize(10.0);

    double minX = std::numeric_limits<double>::max();
    double maxX = std::numeric_limits<double>::lowest();
    double minY = std::numeric_limits<double>::max();
    double maxY = std::numeric_limits<double>::lowest();

    //qDebug() << "Data size:" << data.size();

    if (data.isEmpty()) {
        qDebug() << "No data to display!";
        return;
    }

    for (const auto &point : sampledData) {
        scatterSeries->append(point.getXData(), point.getYData());
        minX = std::min(minX, point.getXData());
        maxX = std::max(maxX, point.getXData());
        minY = std::min(minY, point.getYData());
        maxY = std::max(maxY, point.getYData());
    }

    mainChart->addSeries(scatterSeries);
    mainChart->setTitle(title + " Data Processing Analysis");

    auto axisY = dynamic_cast<QValueAxis *>(mainChart->axes(Qt::Vertical).first());
    if (axisY) {
       //axisY->setTitleText(axisYLabel);
        axisY->setRange(minY, maxY);
    }

    auto axisX = dynamic_cast<QValueAxis *>(mainChart->axes(Qt::Horizontal).first());
    if (axisX) {
        axisX->setRange(minX, maxX);
    }

    currentSeries = scatterSeries;

    //ui->chartHolder->layout()->update();

}


void MainWindow::on_BtnTempChart_clicked(){

    currentSensorType = "Temperature";
    refreshChart(temperatureDataPoints, "Temperature");
}


void MainWindow::on_BtnPressChart_clicked(){
    currentSensorType = "Pressure";
    refreshChart(pressureDataPoints, "Pressure");
}


void MainWindow::on_BtnVoltageChart_clicked(){
    currentSensorType = "Voltage";
    refreshChart(voltageDataPoints, "Voltage");
}

