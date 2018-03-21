#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "libSonar.h"

#include <QBoxLayout>
#include <QWidget>
#include <QSpinBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

    ~MainWindow();
    Sonar sonar;

void timerEvent( QTimerEvent * );

public slots:
    void setDetectRange(int detectRange);


private:

    //***Decleration of wiringPi pin connections***
        int trigger1 = 0;
        int echo1 = 2;
        int motor1 = 3;

        int trigger2 = 23;
        int echo2 = 24;
        int motor2 = 25;

        int trigger3 = 27;
        int echo3 = 28;
        int motor3 = 29;


    QSpinBox *spinbox;

    // layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
    QVBoxLayout  *vLayout;  // vertical layout
    QHBoxLayout  *hLayout;  // horizontal layout

    int detectRange;
};

#endif // MAINWINDOW_H
