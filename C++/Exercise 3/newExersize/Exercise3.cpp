// newExersize.cpp : Defines the entry point for the console application.
//

/*
* Author: Kjell Zijlemaker
* Version: 1.2
* Date: 6-9-2014
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Declaring variables
	int i = 0;
	int j = 0;
	cout << "What number do you want to have the table from?";

	// Getting keyboard action
	cin >> i;

	// While j is smaller or then, or is, 10, it will print the table of the number inserted to 10
	while (j <= 10){
		cout << j << " x " << i << "=" << j*i << "\n";
		j++;
	}

	// Hold the program
	cin.get();
}