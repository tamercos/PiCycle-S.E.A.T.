#include <iostream>
using namespace std;

int main()
{
	int firstNumber, secondNumber, sumOfTwoNumbers;

	cout << "Hello team16, Enter two integers: " << endl;
	cin >> firstNumber >> secondNumber;

	// sum of two numbers in stored in variable sumOfTwoNumbers
	sumOfTwoNumbers = firstNumber + secondNumber;

	// Prints sum 
	cout << firstNumber << " + " << secondNumber << " = " << sumOfTwoNumbers;

	cin.ignore();

	return 0;
}