#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSpinBox>

MainWindow::MainWindow() : sampleRate(10)
{
    spinbox = new QSpinBox;
    spinbox->setValue(sampleRate);
    connect( spinbox, SIGNAL(valueChanged(int)), sampleRate, SLOT(setSampleRate(int)) );
}

void MainWindow::setSampleRate(int sampleRate)
{
    this->sampleRate = sampleRate;
}


MainWindow::~MainWindow()
{

}
