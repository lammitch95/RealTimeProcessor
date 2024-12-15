/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *buttonsPanel;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnStart;
    QPushButton *btnReset;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLabel *sensorNumLbl;
    QLineEdit *SensorAmountTxt;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *LBLProcess;
    QLabel *LblStatus;
    QFrame *ProcessLabels;
    QVBoxLayout *verticalLayout_5;
    QLabel *LblSingleThread;
    QLabel *LblMultiThread;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *SensorTable;
    QVBoxLayout *content;
    QVBoxLayout *chartHolder;
    QHBoxLayout *chartNav;
    QPushButton *BtnTempChart;
    QPushButton *BtnPressChart;
    QPushButton *BtnVoltageChart;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(598, 393);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:  rgb(0, 80, 161);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, 10, 10, 10);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        buttonsPanel = new QFrame(frame);
        buttonsPanel->setObjectName("buttonsPanel");
        buttonsPanel->setFrameShape(QFrame::Shape::StyledPanel);
        buttonsPanel->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(buttonsPanel);
        verticalLayout_2->setObjectName("verticalLayout_2");
        btnStart = new QPushButton(buttonsPanel);
        btnStart->setObjectName("btnStart");
        sizePolicy.setHeightForWidth(btnStart->sizePolicy().hasHeightForWidth());
        btnStart->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        btnStart->setFont(font);
        btnStart->setAutoFillBackground(false);
        btnStart->setStyleSheet(QString::fromUtf8("background-color:  rgb(0, 181, 222);\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 10px;"));

        verticalLayout_2->addWidget(btnStart);

        btnReset = new QPushButton(buttonsPanel);
        btnReset->setObjectName("btnReset");
        sizePolicy.setHeightForWidth(btnReset->sizePolicy().hasHeightForWidth());
        btnReset->setSizePolicy(sizePolicy);
        btnReset->setFont(font);
        btnReset->setStyleSheet(QString::fromUtf8("background-color:  rgb(0, 181, 222);\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 10px;"));

        verticalLayout_2->addWidget(btnReset);


        verticalLayout->addWidget(buttonsPanel);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName("horizontalLayout");
        sensorNumLbl = new QLabel(frame_2);
        sensorNumLbl->setObjectName("sensorNumLbl");
        sensorNumLbl->setFont(font);
        sensorNumLbl->setScaledContents(true);
        sensorNumLbl->setAlignment(Qt::AlignmentFlag::AlignCenter);
        sensorNumLbl->setWordWrap(true);
        sensorNumLbl->setMargin(0);

        horizontalLayout->addWidget(sensorNumLbl);

        SensorAmountTxt = new QLineEdit(frame_2);
        SensorAmountTxt->setObjectName("SensorAmountTxt");

        horizontalLayout->addWidget(SensorAmountTxt);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);

        verticalLayout->addWidget(frame_2);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        LBLProcess = new QLabel(frame_4);
        LBLProcess->setObjectName("LBLProcess");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        LBLProcess->setFont(font1);
        LBLProcess->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_3->addWidget(LBLProcess);

        LblStatus = new QLabel(frame_4);
        LblStatus->setObjectName("LblStatus");
        LblStatus->setFont(font1);
        LblStatus->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_3->addWidget(LblStatus);


        verticalLayout->addWidget(frame_4);

        ProcessLabels = new QFrame(frame);
        ProcessLabels->setObjectName("ProcessLabels");
        ProcessLabels->setFrameShape(QFrame::Shape::StyledPanel);
        ProcessLabels->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_5 = new QVBoxLayout(ProcessLabels);
        verticalLayout_5->setObjectName("verticalLayout_5");
        LblSingleThread = new QLabel(ProcessLabels);
        LblSingleThread->setObjectName("LblSingleThread");
        LblSingleThread->setFont(font1);
        LblSingleThread->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        LblSingleThread->setWordWrap(true);

        verticalLayout_5->addWidget(LblSingleThread);

        LblMultiThread = new QLabel(ProcessLabels);
        LblMultiThread->setObjectName("LblMultiThread");
        LblMultiThread->setFont(font1);
        LblMultiThread->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        LblMultiThread->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        LblMultiThread->setWordWrap(true);

        verticalLayout_5->addWidget(LblMultiThread);


        verticalLayout->addWidget(ProcessLabels);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 2);

        horizontalLayout_2->addWidget(frame);

        frame_5 = new QFrame(centralwidget);
        frame_5->setObjectName("frame_5");
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_5);
        verticalLayout_4->setObjectName("verticalLayout_4");
        SensorTable = new QTableWidget(frame_5);
        if (SensorTable->columnCount() < 3)
            SensorTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        SensorTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        SensorTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        SensorTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (SensorTable->rowCount() < 3)
            SensorTable->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        SensorTable->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        SensorTable->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        SensorTable->setVerticalHeaderItem(2, __qtablewidgetitem5);
        SensorTable->setObjectName("SensorTable");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(SensorTable->sizePolicy().hasHeightForWidth());
        SensorTable->setSizePolicy(sizePolicy1);
        SensorTable->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        SensorTable->setFont(font2);
        SensorTable->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    color: white;\n"
"    gridline-color:  rgb(71, 153, 176);;\n"
"    border-color: rgb(71, 153, 176);\n"
"    font: 10px;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: rgb(71, 153, 176);\n"
"    color: white;\n"
"  \n"
"}\n"
"QTableView::item:focus{\n"
"    border: 2px solid rgb(71, 153, 176);\n"
"    background-color: rgb(255, 254, 229);\n"
"}\n"
"\n"
""));
        SensorTable->setLineWidth(0);
        SensorTable->setMidLineWidth(0);
        SensorTable->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        SensorTable->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        SensorTable->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustToContents);
        SensorTable->setAutoScroll(true);
        SensorTable->setAutoScrollMargin(0);
        SensorTable->setShowGrid(true);
        SensorTable->setGridStyle(Qt::PenStyle::SolidLine);
        SensorTable->setSortingEnabled(false);
        SensorTable->setWordWrap(true);
        SensorTable->setCornerButtonEnabled(true);
        SensorTable->horizontalHeader()->setVisible(true);
        SensorTable->horizontalHeader()->setCascadingSectionResizes(true);
        SensorTable->horizontalHeader()->setMinimumSectionSize(28);
        SensorTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        SensorTable->horizontalHeader()->setStretchLastSection(true);
        SensorTable->verticalHeader()->setCascadingSectionResizes(false);
        SensorTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        SensorTable->verticalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(SensorTable);

        content = new QVBoxLayout();
        content->setObjectName("content");
        chartHolder = new QVBoxLayout();
        chartHolder->setObjectName("chartHolder");

        content->addLayout(chartHolder);

        chartNav = new QHBoxLayout();
        chartNav->setObjectName("chartNav");
        BtnTempChart = new QPushButton(frame_5);
        BtnTempChart->setObjectName("BtnTempChart");
        BtnTempChart->setFont(font);
        BtnTempChart->setStyleSheet(QString::fromUtf8("background-color:  rgb(0, 181, 222);\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 10px;"));

        chartNav->addWidget(BtnTempChart);

        BtnPressChart = new QPushButton(frame_5);
        BtnPressChart->setObjectName("BtnPressChart");
        BtnPressChart->setFont(font);
        BtnPressChart->setStyleSheet(QString::fromUtf8("background-color:  rgb(0, 181, 222);\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 10px;"));

        chartNav->addWidget(BtnPressChart);

        BtnVoltageChart = new QPushButton(frame_5);
        BtnVoltageChart->setObjectName("BtnVoltageChart");
        BtnVoltageChart->setFont(font);
        BtnVoltageChart->setStyleSheet(QString::fromUtf8("background-color:  rgb(0, 181, 222);\n"
"color: white;\n"
"border-radius: 5px;\n"
"padding: 10px;"));

        chartNav->addWidget(BtnVoltageChart);


        content->addLayout(chartNav);

        content->setStretch(0, 6);
        content->setStretch(1, 1);

        verticalLayout_4->addLayout(content);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 3);

        horizontalLayout_2->addWidget(frame_5);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        btnReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        sensorNumLbl->setText(QCoreApplication::translate("MainWindow", "Sensor Amount: ", nullptr));
        SensorAmountTxt->setText(QString());
        LBLProcess->setText(QCoreApplication::translate("MainWindow", "NA: (0/0)", nullptr));
        LblStatus->setText(QCoreApplication::translate("MainWindow", "Status: Active", nullptr));
        LblSingleThread->setText(QCoreApplication::translate("MainWindow", "Generate Sensors: 1000ms", nullptr));
        LblMultiThread->setText(QCoreApplication::translate("MainWindow", "Processing Sensor Data: 5ms", nullptr));
        QTableWidgetItem *___qtablewidgetitem = SensorTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Avg", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = SensorTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = SensorTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = SensorTable->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = SensorTable->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Pressure", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = SensorTable->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Voltage", nullptr));
        BtnTempChart->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        BtnPressChart->setText(QCoreApplication::translate("MainWindow", "Pressure", nullptr));
        BtnVoltageChart->setText(QCoreApplication::translate("MainWindow", "Voltage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
