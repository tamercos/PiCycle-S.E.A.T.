#include <wiringPi.h>
#include <iostream>

using namespace std;

int main()
{
	wiringPiSetup ();
	pinMode (1, OUTPUT);
	for (int counter=0 ; counter<20 ; counter++)
	{
		digitalWrite (1, 1);
		cout << "on" << endl;
		delay (100);
		
		digitalWrite (1, 0);
		cout << "off" << endl;
		delay (100);
	}
	
	return 0;
	
}
