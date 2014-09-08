// Lab 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using std::cout;
using std::fixed;
using std::showpoint;
using std::cin;
using std::endl;
void printResult(int arrayFunction[3][4], int size);

int main()
{
	int multiArray [3][4];
	int sizeOf = sizeof multiArray;

	for (int i = 0; i < sizeOf; i++){
		multiArray[i][i] = rand() % 100;
	}

	printResult(multiArray, sizeOf);
	cin.get();
	
}

void printResult(int arrayFunction[3][4], int size){
	for (int i = 0; i < size; i++){
		cout << arrayFunction[i][i] << "\n";
	}
}