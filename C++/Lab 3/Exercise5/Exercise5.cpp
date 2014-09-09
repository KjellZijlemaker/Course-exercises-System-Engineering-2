// Lab3.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "String"
#include "iostream"

using std::cout;
using std::iostream;
using std::cin;
int distance(int, int);


struct Coordinate
{
	int x;
	int y;
};

int main()
{
	int x = 0;
	int y = 0;

	Coordinate coordinate;

	cout << "Please insert the x coordinate: ";
	cin >> coordinate.x;
	cout << "\nPlease insert the y coordinate: ";
	cin >> coordinate.y;
	cout << "\n\nThe distance of " << x << " and " << y << " is: " << distance(coordinate.x, coordinate.y);
	cin.get();
}

int distance(int x, int y){
	return y - x;
}

