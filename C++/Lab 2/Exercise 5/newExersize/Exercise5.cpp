// newExersize.cpp : Defines the entry point for the console application.
//

/*
* Author: Kjell Zijlemaker
* Version: 1.0
* Date: 6-9-2014
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Declaring variables
	int i = 2;
	int j = 10;

	// creating pointers to integers
	int * pointerI;
	int * pointerJ;

	// Setting pointers to memory locations
	pointerI = &i;
	pointerJ = &j;

	// Printing first batch
	printf("%d\n", pointerI);
	cout << "\n";
	printf("%d\n", pointerJ);

	// Do the same other way
	pointerI = &j;
	pointerJ = &i;

	cout << "\n";

	// Printing the second batch
	printf("%d\n", pointerI);
	cout << "\n";
	printf("%d\n", pointerJ);

	cin.get();
}