#include <iostream>
using namespace std;

int main()
{
	cout << "Hello team16, Please press enter to continue with this exercise" << endl;

	//cin.ignore() allows command prompt to stay up until a key is pressed
	cin.ignore();

	//I'll break yo code with this line' --> fixed it

	int firstNumber, secondNumber, sumOfTwoNumbers;

	cout << "Enter two integers: ";
	cin >> firstNumber >> secondNumber;

	// sum of two numbers in stored in variable sumOfTwoNumbers
	sumOfTwoNumbers = firstNumber + secondNumber;

	// Prints sum 
	cout << firstNumber << " + " << secondNumber << " = " << sumOfTwoNumbers;

	return 0;
}