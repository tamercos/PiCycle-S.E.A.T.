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


public slots:
    void setSampleRate(int sampleRate);


private:
    QSpinBox *spinbox;

    // layout elements from Qt itself http://qt-project.org/doc/qt-4.8/classes.html
    QVBoxLayout  *vLayout;  // vertical layout
    QHBoxLayout  *hLayout;  // horizontal layout

    int sampleRate;
};

#endif // MAINWINDOW_H
