#include "mainwindow.h"
#include "libSonar.h"
#include <wiringPi.h>
#include "ui_mainwindow.h"
#include <QSpinBox>
#include <QCheckBox>
#include <iostream>
#include <iomanip>

MainWindow::MainWindow() : detectRange(10), vibInput1(TRUE), vibInput2(TRUE), vibInput3(TRUE)
{
    button1 = new QCheckBox("Disable left vibration");
    connect( button1, SIGNAL(clicked(bool)), SLOT(setVibInput1(bool)) );

    button2 = new QCheckBox("Disable back vibration");
    connect( button2, SIGNAL(clicked(bool)), SLOT(setVibInput2(bool)) );

    button3 = new QCheckBox("Disable right vibration");
    connect( button3, SIGNAL(clicked(bool)), SLOT(setVibInput3(bool)) );

    scrollbar = new QScrollBar(Qt::Horizontal);
    scrollbar->setValue(detectRange);
    scrollbar->setRange(0, 300);
    connect( scrollbar, SIGNAL(valueChanged(int)), SLOT(setDetectRange(int)) );


    // set up the layout
    vLayout = new QVBoxLayout;
    vLayout->addWidget(scrollbar);

    hLayout = new QHBoxLayout;
    hLayout->addWidget(button1);
    hLayout->addWidget(button2);
    hLayout->addWidget(button3);
    vLayout->addLayout(hLayout);

    setLayout(vLayout);

    sonar.init(trigger1, echo1, vibDisc1, trigger2, echo2, vibDisc2, trigger3, echo3, vibDisc3);
}

void MainWindow::setVibInput1(bool vibInput1)
{
    this->vibInput1 = !vibInput1;
}

void MainWindow::setVibInput2(bool vibInput2)
{
    this->vibInput2 = !vibInput2;
}

void MainWindow::setVibInput3(bool vibInput3)
{
    this->vibInput3 = !vibInput3;
}

void MainWindow::setDetectRange(int detectRange)
{
    this->detectRange = detectRange;
}

void MainWindow::timerEvent( QTimerEvent * )
{
    wiringPiSetup();

     if (vibInput1 == TRUE){
        if (sonar.distance1(3333) < detectRange){				//vibration disc1 condition for activation
            digitalWrite (vibDisc1, HIGH);
            }
            else{
                    digitalWrite (vibDisc1, LOW);
                }
        }

     if (vibInput2 == TRUE){
        if (sonar.distance2(3333) < detectRange){				//vibration disc2 condition for activation
            digitalWrite (vibDisc2, HIGH);
        }
            else{
                    digitalWrite (vibDisc2, LOW);
                }
     }

     if (vibInput1 == TRUE){
        if (sonar.distance3(3333) < detectRange){				//vibration disc3 condition for activation
            digitalWrite (vibDisc3, HIGH);
        }
            else{
                    digitalWrite (vibDisc3, LOW);
                }
     }

        std::cout << "Left: " << std::setprecision(3) << sonar.distance1(3333) << " cm // " << "Back: " << std::setprecision(3)
        << sonar.distance2(3333) << " cm // " << "Right: " << std::setprecision(3) << sonar.distance3(3333) << "cm" << std::endl;

}

MainWindow::~MainWindow()
{

}
