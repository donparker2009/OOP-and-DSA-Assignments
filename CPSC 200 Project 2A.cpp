//Don Parker
//CPSC 200 Project 2A
//A program that reads a file and displays; number of exam scores, average score, standard deviation, and high score.

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	
	ifstream input;
	
	input.open("scores.txt");
	if (input.fail())
	{
		cout << "Couldn't open file\n'";
		exit(1);	
	}	
	
	//tracks sum of scores
	double scoreSum = 0;
	//tracks number of scores
	int num = 0;
	//input from file
	double score;
	//tracks average of all scores
	double mean = 0;
	//tracks highscore at any given time
	double highScore = 0;
	//standard deviation of all scores
	double stdDev;
	//tracks sum of the scores squared (to compute stdDev)
	double squareSum = 0;
	
	while (input >> score)
	{
		num++;
		
		//updating statistical data
		scoreSum = scoreSum + score;
		mean = scoreSum/num;
		squareSum = squareSum + (score * score);
		
		if (score > highScore)
		{
			highScore = score;
		}

	}
	
	//computes standard deviation for scores from file
	stdDev = sqrt( ( (squareSum) / num) - (mean * mean) );
	
	if (num > 0)
	{
		cout << "There are " << num << " exams.\n";
		cout << "The average score is " << mean << " and the standard deviation is " << stdDev << ".\n";
		cout << "The high score is " << highScore << ".\n";
	}
	else
	{
		cout << "File contains no scores. \n";
	}
	return 0;
	
}
