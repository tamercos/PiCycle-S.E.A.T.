#include <iostream>
#include <iomanip>
#include <wiringPi.h>
#include "libSonar.h"

using namespace std;

//***Decleration of wiringPi pin connections***
int trigger1 = 0;
int echo1 = 2;
int motor1 = 3;

int trigger2 = 23;
int echo2 = 24;
int motor2 = 25;

int trigger3 = 27;
int echo3 = 28;
int motor3 = 29;

int detectRange = 10;		//set detection range of sensors (in centimeters) that will act as motor activation condition 
			
int main()
{
    if (wiringPiSetup() == -1)
        return -1;

    Sonar sonar;
    sonar.init(trigger1, echo1, motor1, trigger2, echo2, motor2, trigger3, echo3, motor3);

    while(1)
    {
        
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
			
			
        cout << "Left: " << setprecision(3) << sonar.distance1(3333) << " cm // " << "Back: " << setprecision(3)
		<< sonar.distance2(3333) << " cm // " << "Right: " << setprecision(3) << sonar.distance3(3333) << "cm" << endl;
	}    

}
