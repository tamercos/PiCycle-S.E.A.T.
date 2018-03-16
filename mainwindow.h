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

    void timerEvent( QTimerEvent * );


public slots:
    void setSampleRate(int sampleRate);


private:
    QSpinBox *spinbox;

    // layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
    QVBoxLayout  *vLayout;  // vertical layout
    QHBoxLayout  *hLayout;  // horizontal layout

    static const int plotDataSize = 100;

    // data arrays for the plot
    double xData[plotDataSize];
    double yData[plotDataSize];

    int sampleRate;
    int count;
};

#endif // MAINWINDOW_H
