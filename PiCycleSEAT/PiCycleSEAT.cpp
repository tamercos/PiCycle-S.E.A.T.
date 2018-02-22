#include <iostream>
#include <iomanip>
#include <wiringPi.h>
#include "libSonar.h"

using namespace std;

//***Decleration of wpi pin connections***
int trigger1 = 7;
int echo1 = 0;
int motor1 = 1;

int trigger2 = 4;
int echo2 = 5;
int motor2 = 3;

int trigger3 = 21;	//These pins are to change upon arrival of RPi 3!!!
int echo3 = 22;
int motor3 = 23;


int main()
{
    if (wiringPiSetup() == -1)
        return -1;

    Sonar sonar;
    sonar.init(trigger1, echo1, motor1, trigger2, echo2, motor2, trigger3, echo3, motor3);

    while(1)
    {
        
        if (sonar.distance1(30000) < 10.0){				//motor1 condition for activation
			digitalWrite (motor1, HIGH);
		}
			else{
					digitalWrite (motor1, LOW);
				}
        
        
        if (sonar.distance2(30000) < 10.0){				//motor2 condition for activation
			digitalWrite (motor2, HIGH);
		}
			else{
					digitalWrite (motor2, LOW);
				}
				
				
		if (sonar.distance3(30000) < 10.0){				//motor3 condition for activation
			digitalWrite (motor3, HIGH);
		}
			else{
					digitalWrite (motor3, LOW);
				}
			
			
		cout << "Left: " << setprecision(1) << sonar.distance1(30000) << " cm // " << "Back: " << setprecision (1) << sonar.distance2(30000) << " cm // " << "Right: " << setprecision(1) << sonar.distance3(30000) << "cm" << endl;
	}    

}
