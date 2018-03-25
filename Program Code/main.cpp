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

    // call the mainwindow.timerEvent function every 40 ms
    w.startTimer(40);

    return a.exec();
}
