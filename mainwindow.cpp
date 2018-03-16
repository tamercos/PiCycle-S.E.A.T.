#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSpinBox>

MainWindow::MainWindow() : sampleRate(10)
{
    spinbox = new QSpinBox;
    spinbox->setValue(sampleRate);
    connect( spinbox, SIGNAL(valueChanged(int)), SLOT(setSampleRate(int)) );


    // set up the layout
    vLayout = new QVBoxLayout;
    vLayout->addWidget(spinbox);

    hLayout = new QHBoxLayout;
    hLayout->addLayout(vLayout);

    setLayout(hLayout);

}

void MainWindow::setSampleRate(int sampleRate)
{
    this->sampleRate = sampleRate;
}


MainWindow::~MainWindow()
{

}
