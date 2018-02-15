#include <iostream>
#include <wiringPi.h>
#include "libSonar.h"

using namespace std;

int trigger1 = 7;
int echo1 = 0;
int trigger2 = 4;
int echo2 = 5;
int motor1 = 1;
int motor2 = 3;
int motor3 = 6;


int main()
{
    if (wiringPiSetup() == -1)
        return -1;

    Sonar sonar;
    sonar.init(trigger1, echo1, trigger2, echo2, motor1, motor2);

    while(1)
    {
        cout << "1st distance is " << sonar.distance1(30000) << " cm : " << "2nd distance is " << sonar.distance2(30000) << " cm" << endl;
        
        if (sonar.distance1(30000) < 10.0)	//sonar1 and motor1
		{
			digitalWrite (motor1, HIGH);
			//digitalWrite (motor2, LOW);
		}
			else
				{
					digitalWrite (motor1, LOW);
				}
        
        if (sonar.distance2(30000) < 10.0)	//sonar 2 and motor2
		{
			digitalWrite (motor2, HIGH);
			//digitalWrite (motor1, LOW)
		}
			else
				{
					digitalWrite (motor2, LOW);
				}
		if ((sonar.distance2(30000) < 10.0) && (sonar.distance1(30000) < 10.0))
		{
			digitalWrite (motor3, HIGH);
		}
			else
				{
					digitalWrite (motor3, LOW);
				}
			
	}
    

}
