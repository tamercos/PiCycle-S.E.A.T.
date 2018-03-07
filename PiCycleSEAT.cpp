#include <iostream>
#include <iomanip>
#include <wiringPi.h>
#include "libSonar.h"

using namespace std;

//***Decleration of wpi pin connections***
int trigger1 = 0;
int echo1 = 2;
int motor1 = 3;

int trigger2 = 23;
int echo2 = 24;
int motor2 = 25;

int trigger3 = 27;
int echo3 = 28;
int motor3 = 29;


int main()
{
    if (wiringPiSetup() == -1)
        return -1;

    Sonar sonar;
    sonar.init(trigger1, echo1, motor1, trigger2, echo2, motor2, trigger3, echo3, motor3);

    while(1)
    {
        
        if (sonar.distance1(3000) < 10.0){				//motor1 condition for activation
			digitalWrite (motor1, HIGH);
		}
			else{
					digitalWrite (motor1, LOW);
				}
        
        
        if (sonar.distance2(3000) < 10.0){				//motor2 condition for activation
			digitalWrite (motor2, HIGH);
		}
			else{
					digitalWrite (motor2, LOW);
				}
				
				
		if (sonar.distance3(3000) < 10.0){				//motor3 condition for activation
			digitalWrite (motor3, HIGH);
		}
			else{
					digitalWrite (motor3, LOW);
				}
			
			
		cout << "Left: " << setprecision(3) << sonar.distance1(3000) << " cm // " << "Back: " << setprecision(3) << sonar.distance2(3000) << " cm // " << "Right: " << setprecision(3) << sonar.distance3(30000) << "cm" << endl;
	}    

}
