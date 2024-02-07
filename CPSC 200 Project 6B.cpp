//Don Parker
//CPSC 200 Project 6B
//A program that converts a decimal non-negative integer to binary recursively

#include<iostream>
using namespace std;

//Takes a non-negative decimal integer input and converts to binary
void printBinary(int decNum)
{
	if (decNum <= 0) //Base Case
		cout << 0;
	else
	{
		printBinary(decNum / 2);
		cout << decNum % 2;
	}
	
}

int main()
{
	int decimalNumber;
	
	cout << "Enter a decimal number: ";
	cin >> decimalNumber;
	
	cout << decimalNumber << " in binary is: "; printBinary(decimalNumber);
	
	return 0;
}
