QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Add include directory
INCLUDEPATH += include

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/datapoint.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/pressuresensor.cpp \
    src/sensordataprocessor.cpp \
    src/temperaturesensor.cpp \
    src/databasehandle.cpp \
    src/sensorsimulator.cpp \
    src/voltagesensor.cpp \
    src/threadpool.cpp \

HEADERS += \
    include/databasehandle.h \
    include/datapoint.h \
    include/mainwindow.h \
    include/pressuresensor.h \
    include/sensordataprocessor.h \
    include/sensorsimulator.h \
    include/temperaturesensor.h \
    include/voltagesensor.h \
    include/threadpool.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
