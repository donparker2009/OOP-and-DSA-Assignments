//Don Parker
//CPSC 200 Project 6A
//A program that finds the factorial of a non-negative integer recursively

#include<iostream>
using namespace std;

//Takes a non-negative integer input and outputs that number's factorial.
int fact(int num)
{
	if (num < 2) //Base Case
		return 1;
	else
		return num * fact(num - 1);
}

int main()
{
	int number;
	
	cout << "Enter a number to take factorial of: ";
	cin >> number;
	
	cout << number << "! = " << fact(number);
		
	return 0;
}
