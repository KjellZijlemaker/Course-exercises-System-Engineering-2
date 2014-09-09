// lab3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;
void printResult(int arrayFunction[3][4]);

int main()
{
	int multiArray[3][4];
	for (int i = 0; i <= 3; i++){
		for (int j = 0; j <= 4; j++){
			multiArray[i][j] = (rand() % 100) +1;
		}	
	}

	printResult(multiArray);
	cin.get();

}

void printResult(int arrayFunction[3][4]){
	ofstream newFile;
	newFile.open("Resultaten.txt");
	cout << "Writing to file... Please wait\n";
	for (int i = 0; i <= 3; i++){
		for (int j = 0; j <= 4; j++){
			newFile << arrayFunction[i][j] << "\n";
		}
	}
	cout << "\nDone!";
	newFile.close();
}