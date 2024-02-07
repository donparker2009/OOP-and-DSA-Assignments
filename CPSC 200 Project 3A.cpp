//Don Parker
//CPSC 200 Project 3A
//A program that reduces a fraction

#include<iostream>
#include<cmath>
using namespace std;

//returns the greatest common denominator given two positive integers
int gcd(int num1,int num2)
{
	if (num1 == 0)
		return num2;
	if (num2 == 0)
		return num1;
		
	if (num1 == num2)
		return num1;
		
	if (num1 > num2)
		return gcd(num1 - num2,num2);
	
	return gcd(num1,num2 - num1);
}

//reduces and prints a fraction given a numerator and denominator
void reduce(int numerator,int denominator)
{
	cout << numerator/gcd(numerator,denominator) << "/" << denominator/gcd(numerator,denominator) << endl;
}

int main()
{
	int numerator,denominator,abs_Numerator,abs_Denominator;
	
	cout << "Enter the numerator: ";
	cin >> numerator;
	
	cout << "Enter the denominator: ";
	cin >> denominator;
	
	//absolute value of numerator and denominator
	abs_Numerator = sqrt( numerator * numerator);
	abs_Denominator = sqrt( denominator * denominator);
	
	if (denominator == 0)
		cout << "undefined\n";
	else
	{
		if (denominator != 0 && numerator % denominator == 0)
			cout << numerator << "/" << denominator << " = " << numerator/denominator << endl;
		else
		{
			if (numerator == 0)
			{
				cout << numerator << "/" << denominator << " = " << 0 << endl;
			}
			if (denominator == 1 && numerator != 0)
			{
				cout << numerator << "/" << denominator << " = " << numerator << endl;
			}
			if ((numerator * abs_Denominator)/(denominator * abs_Numerator) == -1)
			{
				cout << numerator << "/" << denominator << " = -";
				reduce(abs_Numerator,abs_Denominator);
			}
			else 
			{
				cout << numerator << "/" << denominator << " = ";
				reduce(abs_Numerator,abs_Denominator);
			}
		}
	}
	return 0;
}
