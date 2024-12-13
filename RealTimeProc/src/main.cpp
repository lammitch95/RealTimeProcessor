#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //quick test

    MainWindow w;
    w.show();
    return a.exec();
}
