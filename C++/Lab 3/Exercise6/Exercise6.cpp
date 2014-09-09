// Lab3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "String"
#include "iostream"

using std::cout;
using std::iostream;
using std::cin;
int distance(int *a, int *b);


int main()
{
	int *a = new int;
	int *b = new int;
	

	cout << "Please insert variable A: ";
	cin >> *a;

	cout << "\n\nPlease insert variable B: ";
	cin >> *b;

	cout  <<  "\n\n" << distance (a, b);

	delete a;
	delete b;

	cin.get();
}

int distance(int *a, int *b){
	int *c = new int;
	*c = *a + *b;
	return *c;
}

