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
	int i;

	cout << "Please type a number from 1 - 5: ";
	cin >> i;

	switch (i)
	{
	case 1:
		cout << "6";
		break;
	case 2:
		cout << "sea";
		break;
	case 3:
		cout << "7";
		break;
	case 4:
		cout << "-21";
		break;
	case 5:
		cout << "Yes";
		break;
	default:
		cout << "A";
		break;
	}

	cin.get();
	
}