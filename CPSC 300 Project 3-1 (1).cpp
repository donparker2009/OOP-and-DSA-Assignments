// Don Parker
// CPSC 300 Project 3
// A program that takes a string numerator and an int denominator and returns and integer remainder after division.

#include <iostream>
using namespace std;

//Takes a string numerator and int denominator returns int remainder.
int remainder(string numerator, int denominator)
{
	int mod = 0;
	
	for (int i = 0; i < numerator.length(); i++)
		{
			mod = mod + numerator[i] - '0';
			mod = mod % denominator;
			
			if ( i < (numerator.length() - 1) )
			{
				mod = mod * 10;
			}
			else
			{
				return mod;
			}
		}
}

int main()
{
	string num;
	int den;
	
	cout << "Enter numerator: \n";
	cin >> num;
	
	cout << "Enter denominator: \n";
	cin >> den;
	
	cout << num << " " << "MOD " << den << " = " << remainder(num,den) << endl;
	
	
	return 0;
}
