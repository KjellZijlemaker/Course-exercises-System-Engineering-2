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
	// Declaring variables and initializing as needed
	int i = 0;
	int j = 7;
	int k = 10;
	int l;
	int o = 1;

	// creating pointers to integers
	int * pointer_forLoop;
	int * pointer_Table;
	int * pointer_SmallerThen;
	int * pointer_TableResult;
	int * pointer_incrementor;

	// Setting pointers to memory locations
	pointer_forLoop = &i;
	pointer_Table = &j;
	pointer_SmallerThen = &k;
	pointer_TableResult = &l;
	pointer_incrementor = &o;

	// Making for loop with only the pointers to use
	for (*pointer_forLoop; *pointer_forLoop <= *pointer_SmallerThen; *pointer_forLoop += *pointer_incrementor){

		// Computing the result of the table with pointers
		*pointer_TableResult = *pointer_forLoop * *pointer_Table;

		// Showing the results with the pointers
		cout<< *pointer_forLoop << " x " << *pointer_Table << " = " << *pointer_TableResult << "\n";
	}

	cin.get();
}