// Lab 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using std::cout;
using std::fixed;
using std::showpoint;
using std::cin;
using std::endl;
int distance(int x, int y);

int main()
{
	int multiArray [3][4];

	for (int i = 0; i < sizeof(multiArray); i++){
		multiArray[i][i] = rand() % 100;
		cout << multiArray[i][i] << "\n";
	}

	cin.get();
	
}