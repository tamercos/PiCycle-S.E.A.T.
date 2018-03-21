#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <iomanip>
#include <wiringPi.h>
#include "libSonar.h"

using namespace std;

int detectRange;		//set detection range of sensors (in centimeters) that will act as motor activation condition

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.startTimer(40);

    return a.exec();
}
