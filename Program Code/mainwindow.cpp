#include "mainwindow.h"
#include "libSonar.h"
#include <wiringPi.h>
#include "ui_mainwindow.h"
#include <QCheckBox>
#include <QScrollBar>
#include <iostream>
#include <iomanip>

MainWindow::MainWindow() : detectRange(10), vibInput1(TRUE), vibInput2(TRUE), vibInput3(TRUE)
{
   Sonar sonar;

 /**********************************
  * Assigning widget functionality *
  **********************************/
    checkBox1 = new QCheckBox("Disable left");
    connect( checkBox1, SIGNAL(clicked(bool)), SLOT(setVibInput1(bool)) );

    checkBox2 = new QCheckBox("Disable back");
    connect( checkBox2, SIGNAL(clicked(bool)), SLOT(setVibInput2(bool)) );

    checkBox3 = new QCheckBox("Disable right");
    connect( checkBox3, SIGNAL(clicked(bool)), SLOT(setVibInput3(bool)) );

    scrollbar = new QScrollBar(Qt::Horizontal);
    scrollbar->setValue(detectRange);
    scrollbar->setRange(0, 300);                 //setting the scrollbar range between 0 to 3 meters
    connect( scrollbar, SIGNAL(valueChanged(int)), SLOT(setDetectRange(int)) );

    sblabel = new QLabel;
    sblabel->setText("Set detection range (0m-3m)");

 /********************
  * set up UI layout *
  ********************/
    vLayout = new QVBoxLayout;
    vLayout->setContentsMargins(30,60,30,80);
    vLayout->addWidget(sblabel);
    sblabel->setAlignment(Qt::AlignCenter);
    vLayout->addWidget(scrollbar);

    hLayout = new QHBoxLayout;
    hLayout->setContentsMargins(10,50,0,0);
    hLayout->addWidget(checkBox1);
    hLayout->addWidget(checkBox2);
    hLayout->addWidget(checkBox3);
    vLayout->addLayout(hLayout);

    setLayout(vLayout);

}

void MainWindow::setVibInput1(bool vibInput1)           //Varies value between TRUE and FALSE upon each click of the checkbox
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


/******************************************
 * Timer event that will run continuously *
 ******************************************/
void MainWindow::timerEvent( QTimerEvent * )
{

     if (vibInput1 == TRUE){                                    //vibInput is tied to the checkbox. If checkbox value is TRUE, then run the following IF loop. Otherwise, default to deactive

            if (sonar.distance1(3333) < detectRange){           //vibration disc1 condition for activation. If distance is less than the detection range, vibration disc is activated
                digitalWrite (sonar.getVibDisc1(), HIGH);
                }
                else{                                           //otherwise, the vibration disc is deactivated
                       digitalWrite (sonar.getVibDisc1(), LOW);
                    }
            }

        else{
               digitalWrite (sonar.getVibDisc1(), LOW);
            }

     if (vibInput2 == TRUE){

            if (sonar.distance2(3333) < detectRange){			//vibration disc2 condition for activation
                digitalWrite (sonar.getVibDisc2(), HIGH);
                }
                else{
                       digitalWrite (sonar.getVibDisc2(), LOW);
                    }
        }
        else{
               digitalWrite (sonar.getVibDisc2(), LOW);
            }


     if (vibInput3 == TRUE){
            if (sonar.distance3(3333)  < detectRange){			//vibration disc3 condition for activation
                digitalWrite (sonar.getVibDisc3(), HIGH);
            }
                else{
                       digitalWrite (sonar.getVibDisc3(), LOW);
                    }
        }
        else{
               digitalWrite (sonar.getVibDisc3(), LOW);
            }

        std::cout << "Left: " << std::setprecision(3) << sonar.distance1(3333) << " cm // " << "Back: " << std::setprecision(3)
        << sonar.distance2(3333) << " cm // " << "Right: " << std::setprecision(3) << sonar.distance3(3333) << "cm" << std::endl;

}

MainWindow::~MainWindow()
{

}
