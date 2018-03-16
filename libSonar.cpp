#include <iostream>
#include <wiringPi.h>
#include "libSonar.h"

Sonar::Sonar(){}

void Sonar::init(int trigger1, int echo1, int motor1, int trigger2, int echo2, int motor2,int trigger3, int echo3, int motor3)
{
    this->trigger1=trigger1;
    this->echo1=echo1;
    this->trigger2=trigger2;
    this->echo2=echo2;
    this->trigger3=trigger3;
    this->echo3=echo3;
    pinMode(trigger1, OUTPUT);			//defining trigger, echo and motor pins as input or output
    pinMode(echo1, INPUT);
    pinMode(motor1, OUTPUT);
    pinMode(trigger2, OUTPUT);
    pinMode(echo2, INPUT);
    pinMode(motor2, OUTPUT);
    pinMode(trigger3, OUTPUT);
    pinMode(echo3, INPUT);
    pinMode(motor3, OUTPUT);
    digitalWrite(trigger1, LOW);		//ensuring trigger and motor outputs start in inactive state
    digitalWrite(trigger2, LOW);
    digitalWrite(trigger3, LOW);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    delay(500);
}
/***********************************
  Distance Measurement for 1st Sonar
 ***********************************/
void Sonar::recordPulseLength1()
{
    startTimeUsec1 = micros();
    while ( digitalRead(echo1) == HIGH );
    endTimeUsec1 = micros();
}

double Sonar::distance1(int timeout1)
{
    digitalWrite(trigger1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger1, LOW);

    now1=micros();

    while (digitalRead(echo1) == LOW && micros() - now1 < timeout1);
    recordPulseLength1();

    travelTimeUsec1 = endTimeUsec1 - startTimeUsec1;
    distanceMeters1 = 100*((travelTimeUsec1/1000000.0)*340.29)/2;

    return distanceMeters1;
}

/***********************************
  Distance Measurement for 2nd Sonar
 ***********************************/
void Sonar::recordPulseLength2()
{
    startTimeUsec2 = micros();
    while ( digitalRead(echo2) == HIGH );
    endTimeUsec2 = micros();
}

double Sonar::distance2(int timeout2)
{
    digitalWrite(trigger2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger2, LOW);

    now2=micros();

    while (digitalRead(echo2) == LOW && micros() - now2 < timeout2);
    recordPulseLength2();

    travelTimeUsec2 = endTimeUsec2 - startTimeUsec2;
    distanceMeters2 = 100*((travelTimeUsec2/1000000.0)*340.29)/2;
    
    return distanceMeters2;
}

/***********************************
  Distance Measurement for 3rd Sonar
 ***********************************/
void Sonar::recordPulseLength3()
{
    startTimeUsec3 = micros();
    while ( digitalRead(echo3) == HIGH );
    endTimeUsec3 = micros();
}

double Sonar::distance3(int timeout3)
{
    digitalWrite(trigger3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger3, LOW);

    now3=micros();

    while (digitalRead(echo3) == LOW && micros() - now3 < timeout3);
    recordPulseLength3();

    travelTimeUsec3 = endTimeUsec3 - startTimeUsec3;
    distanceMeters3 = 100*((travelTimeUsec3/1000000.0)*340.29)/2;

    return distanceMeters3;
}

