#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <iomanip>
#include <wiringPi.h>
#include "libSonar.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.showMaximized();

    w.startTimer(40);

    return a.exec();
}
