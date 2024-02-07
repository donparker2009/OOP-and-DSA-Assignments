//Don Parker
//CPSC 200 Project 2B
//Returns whether or not a given year is a leap year

#include<iostream>
using namespace std;

//Takes a year input and returns true if leap year, else returns false.
bool isLeapYear(int year)
{
	
	if (year % 400 == 0)
	{
		return true;
	}
	else
	{
		if (year % 4 == 0 && year % 100 != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	
	int year = 1;
	
	while (year != 0)
	{
	
		cout << "Enter a year (0 to stop): ";
		cin >> year;
	
	
		if (year == 0)
		{
			cout << "Bye.";
			break;
		}
		if (isLeapYear(year) != true)
		{
			cout << "not a leap year\n";
		}
		else
		{
			cout << "is leap year\n";
		}
		
	}
		
	return 0;
	
}
