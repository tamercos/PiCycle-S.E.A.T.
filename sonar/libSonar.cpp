#include <iostream>
#include <wiringPi.h>
#include "libSonar.h"

Sonar::Sonar(){}

void Sonar::init(int trigger1, int echo1, int trigger2, int echo2, int motor1, int motor2)
{
    this->trigger1=trigger1;
    this->echo1=echo1;
    this->trigger2=trigger2;
    this->echo2=echo2;
    pinMode(trigger1, OUTPUT);
    pinMode(echo1, INPUT);
    pinMode(trigger2, OUTPUT);
    pinMode(echo2, INPUT);
    pinMode(motor1, OUTPUT);
    pinMode(motor2, OUTPUT);
    digitalWrite(trigger1, LOW);
    digitalWrite(trigger2, LOW);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
    delay(500);
}


void Sonar::recordPulseLength1()	//distance measurements for 1st sonar
{
    startTimeUsec1 = micros();
    while ( digitalRead(echo1) == HIGH );
    endTimeUsec1 = micros();
}

double Sonar::distance1(int timeout)
{
    delay(10);

    digitalWrite(trigger1, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigger1, LOW);

    now1=micros();

    while (digitalRead(echo1) == LOW && micros()-now1<timeout);
    recordPulseLength1();

    travelTimeUsec1 = endTimeUsec1 - startTimeUsec1;
    distanceMeters1 = 100*((travelTimeUsec1/1000000.0)*340.29)/2;

    return distanceMeters1;
}

void Sonar::recordPulseLength2()	//distance measurment for 2nd sonar
{
    startTimeUsec2 = micros();
    while ( digitalRead(echo2) == HIGH );
    endTimeUsec2 = micros();
}

double Sonar::distance2(int timeout)
{
    delay(10);

    digitalWrite(trigger2, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigger2, LOW);

    now2=micros();

    while (digitalRead(echo2) == LOW && micros()-now2<timeout);
    recordPulseLength2();

    travelTimeUsec2 = endTimeUsec2 - startTimeUsec2;
    distanceMeters2 = 100*((travelTimeUsec2/1000000.0)*340.29)/2;

    return distanceMeters2;
}

