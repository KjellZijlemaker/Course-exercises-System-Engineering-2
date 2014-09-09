// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String"
#include "iostream"

using std::cout;
using std::iostream;
using std::cin;
int distance(int, int);

int main()
{
	int x = 0;
	int y = 0;
	cout << "Please insert the x coordinate: ";
	cin >> x;
	cout << "\nPlease insert the y coordinate: ";
	cin >> y;
	cout << "\n\nThe distance of " << x << " and " << y << " is: " << distance(x, y);
	cin.get();
}

int distance(int x, int y){
	return y - x;
}