//Don Parker
//CPSC 200 Project 1B
//A program that computes the first n cubes where n is given by the user.

#include<iostream>
using namespace std;

int main()
{
	int numberCubes,tracker = 1;
	
	cout << "How many cubes?: ";
	cin >> numberCubes;
	
	while (tracker <= numberCubes)
	{
		cout << tracker << " cubed is " << tracker * tracker * tracker << endl;
		tracker++;
	}
	
	return 0;
	
}
