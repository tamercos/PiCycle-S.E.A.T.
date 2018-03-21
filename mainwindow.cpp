#include "mainwindow.h"
#include "libSonar.h"
#include <wiringPi.h>
#include "ui_mainwindow.h"
#include <QSpinBox>
#include <iostream>
#include <iomanip>

MainWindow::MainWindow() : detectRange(10)
{
    spinbox = new QSpinBox;
    spinbox->setValue(detectRange);
    connect( spinbox, SIGNAL(valueChanged(int)), SLOT(setDetectRange(int)) );


    // set up the layout
    vLayout = new QVBoxLayout;
    vLayout->addWidget(spinbox);

    hLayout = new QHBoxLayout;
    hLayout->addLayout(vLayout);

    setLayout(hLayout);

    sonar.init(trigger1, echo1, motor1, trigger2, echo2, motor2, trigger3, echo3, motor3);
}

void MainWindow::setDetectRange(int detectRange)
{
    this->detectRange = detectRange;
}

void MainWindow::timerEvent( QTimerEvent * )
{
    wiringPiSetup();

        if (sonar.distance1(3333) < detectRange){				//motor1 condition for activation
            digitalWrite (motor1, HIGH);
        }
            else{
                    digitalWrite (motor1, LOW);
                }


        if (sonar.distance2(3333) < detectRange){				//motor2 condition for activation
            digitalWrite (motor2, HIGH);
        }
            else{
                    digitalWrite (motor2, LOW);
                }


        if (sonar.distance3(3333) < detectRange){				//motor3 condition for activation
            digitalWrite (motor3, HIGH);
        }
            else{
                    digitalWrite (motor3, LOW);
                }

        std::cout << "Left: " << std::setprecision(3) << sonar.distance1(3333) << " cm // " << "Back: " << std::setprecision(3)
        << sonar.distance2(3333) << " cm // " << "Right: " << std::setprecision(3) << sonar.distance3(3333) << "cm" << std::endl;

}

MainWindow::~MainWindow()
{

}
