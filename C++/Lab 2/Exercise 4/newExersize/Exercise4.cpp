// newExersize.cpp : Defines the entry point for the console application.
//

/*
* Author: Kjell Zijlemaker
* Version: 1.0
* Date: 6-9-2014
*/

#include "stdafx.h"
#include <iostream>
#include <ctime> // For pure randomization
#include <cstdlib>
#include <string>
#include <Windows.h>

using namespace std;

// Setting the methods!
int guessNumber();
void checkIfSuccess(int, int);

int main()
{
	// Declaring variables
	int randomNumber;
	int numberIn;
	int totalGuesses = 0;

	// Setting random number with random ensured because of the time given
	srand(time(0)); 

	// Randomizing number between 1-15
	randomNumber = rand() % 15 + 1; 

	// Taking number in variable
	numberIn = guessNumber();

	// Check if success or not..
	checkIfSuccess(randomNumber, numberIn);

	// While not succesfull, do it all over again..
	while (randomNumber != numberIn){
		string tryAgain;
		totalGuesses++;
		cout << "Sorry that's wrong... :(\n";
		cout << "\nYou have made " << totalGuesses << " guesses so far\n";
		cout << "Want to try again?  Y/N\n";
		cin >> tryAgain;

		// If Y is not given, it the game will end
		if (tryAgain != "y"){
			cout << "\nThank you for playing the game! Tik anything on keyboard to exit..";
			cin.get();
			break;
		}

		// Guess number again
		numberIn = guessNumber();

		// Check if success again
		checkIfSuccess(randomNumber, numberIn);
	}

	// Hold the program
	cin.get();
}

int guessNumber(){
	int numberIn;
	cout << "\nPlease guess the number I have under my hat bro! It's between 1-15!!\n";

	// Taking number in variable
	cin >> numberIn;

	cout << "\nThinking...\n";

	// Let it sleep!!
	Sleep(1000);

	// Return the inserted number
	return numberIn;
}

// Check if numbers are matching or not..
void checkIfSuccess(int randomNumber, int numberIn){
	if (numberIn == randomNumber){
		cout << "\nCongrats! You have succesfully guessed the number under my hat! :)";
		cin.get();
	}
}