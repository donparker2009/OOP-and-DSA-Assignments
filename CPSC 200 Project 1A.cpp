//Don Parker
//CPSC 200 Project 1A
//Program for practicing multiplication of two integers.

#include<iostream>
using namespace std;

int main()
{
	int firstNum, secondNum, guess;
	
	cout << "1st number: ";
	cin >> firstNum;
	
	cout << "2nd number: ";
	cin >> secondNum;
	
	cout << "What's " << firstNum << " times " << secondNum << "? : ";
	cin >> guess;
	
	if (guess == firstNum * secondNum)
	{
		cout << "Right!";
		
	}	
	else 
	{
		cout << "Wrong! The correct answer is " << firstNum * secondNum << ".";
	}
	
	return 0;
}
