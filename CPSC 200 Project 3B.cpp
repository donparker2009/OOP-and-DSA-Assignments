//Don Parker
//CPSC 200 Project 3B
//A program that figures change

#include<iostream>
using namespace std;

int main()
{
	double purchase,tender,change;
	int dollars,cents,quarters,dimes,nickels,pennies;
	
	cout << "Enter the purchase amount: ";
	cin >> purchase;
	
	cout << "Enter the amount tendered: ";
	cin >> tender;
	
	change = tender - purchase + .005;
	
	dollars = change;
	cents = (change - dollars) * 100;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "Your change is $" << dollars + cents/100.0 << endl;
	
	//dollars
	if (dollars == 1)
		cout << "1 dollar ";
	if (dollars > 1)
		cout << dollars << " dollars ";
		
	//quarters
	quarters = (cents - (cents % 25) ) / 25;
	cents = cents - 25 * quarters;
	if (quarters == 1)
		cout << "1 quarter ";
	if (quarters > 1)
		cout << quarters << " quarters ";
		
	//dimes
	dimes =  (cents - (cents % 10) ) / 10;
	cents = cents - 10 * dimes;
	if (dimes == 1)
		cout << "1 dime ";
	if (dimes > 1)
		cout << dimes << " dimes ";
		
	//nickels (only 0 or 1 possible)
	nickels = (cents - (cents % 5) ) / 5;
	cents = cents - 5 * nickels;
	if (nickels == 1)
		cout << "1 nickel ";
		
	//pennies	
	pennies = cents;
	if (pennies == 1)
		cout << "1 penny ";
	if (pennies > 1)
		cout << pennies << " pennies ";
	
	return 0;
}
	
	
