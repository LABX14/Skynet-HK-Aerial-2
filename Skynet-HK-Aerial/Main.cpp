// Kaulana Lee
// 7/3/21
// Skynet Aerial Assignment

#include <cstdlib>
#include <ctime>
#include <iostream>

// These are the Preprocessors Directives
using std::cout;
using std::endl;

int main()
{
	srand(static_cast<unsigned int>(time(0)));//seed random number generator
	int EnemyLocation = rand() % 64 + 1;

	int searchHigh = 64; // SearchHigh will be set to 64
	int searchLow = 1; // SearchLow will be set to 1

	int guess = (searchHigh - searchLow) / 2 + searchLow; //This is the equation for the guess

	int tries = 1; //This determine the number of tries you have

	cout << "Welcome To Skynet" << endl;
	cout << "Starting Search of 8 by 8 Grid." << endl;
	cout << "------------------------------" << endl;

	// This will check to see if the guess is right and will adjust it if it is too low or too high
	do {
		if (guess < EnemyLocation)
		{
			cout << "Guess # " << tries << ": " << guess << endl;
			searchLow = guess + 1; // This adds 1 to your guess
			guess = (searchHigh - searchLow) / 2 + searchLow; // This makes a new low by cutting it in half
			cout << "Guess was too low. New guess is " << guess << ". " << endl;
			cout << "---------------------------------" << endl;
			++tries;
		}

		else
		{
			cout << "Guess # " << tries << ": " << guess << endl;
			searchHigh = guess - 1; // This minuses 1 from your guess
			guess = (searchHigh - searchLow) / 2 + searchLow; //This makes a new high by cutting it in half 
			cout << "Guess was too high. New guess is " << guess << ". " << endl;
			cout << "---------------------------------" << endl;
			++tries;
		}
	} while (guess != EnemyLocation);

	cout << "Search complete." << endl;
	cout << "Enemy found at position " << EnemyLocation << "." << endl;
	cout << "Search took " << tries << " preditctions to find enemy." << endl;

	return 0;
}