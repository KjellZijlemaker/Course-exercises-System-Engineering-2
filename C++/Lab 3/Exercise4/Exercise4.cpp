// lab3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "iostream"

using std::cout;
using std::fixed;
using std::showpoint;
using std::cin;
using std::endl;
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
	for (int i = 0; i <= 3; i++){
		for (int j = 0; j <= 4; j++){
			cout << arrayFunction[i][j] << "\n";
		}
		
	}
}