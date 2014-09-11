// Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstring>

// Declaring methods..
void createProcesses();
void printProcesses();
void writeBinaryFile(int &process, int &length, char *created, char *modified, int &number);

using namespace std;

// Making structure for processes
struct str_process{
	int process_id;
	int length;
	char *created;
	char *modified;
	str_process *next;
};

// Creating the nullpointer for next process
str_process* nextProcess = NULL;

// Making a new pointer to the process, for making a new one
str_process* getNewProcess(){

	// Initialize new process
	str_process* process = new str_process;

	// Pointer goes to the nextProcess (temp pointer)
	process->next = nextProcess;

	// TempPointer points to the new process now (new node)
	nextProcess = process;
	return nextProcess;
}


int main()
{
	
	// Making the structures
	str_process* n1 = getNewProcess();
	n1->process_id = 12;
	n1->length = 120;
	n1->created = "08092014";
	n1->modified = "08092013";

	str_process* n2 = getNewProcess();
	n2->process_id = 23;
	n2->length = 99;
	n2->created = "02082014";
	n2->modified = "10082014";

	str_process* n3 = getNewProcess();
	n3->process_id = 17;
	n3->length = 134;
	n3->created = "08092011";
	n3->modified = "09092011";

	// Declaring array
	int newProcess[4][5];


	// Setting data
	newProcess[1][1] = n1->process_id;
	newProcess[1][2] = n1->length;
	newProcess[1][3] = atoi(n1->created);
	newProcess[1][4] = atoi(n1->modified);

	newProcess[2][1] = n2->process_id;
	newProcess[2][2] = n2->length;
	newProcess[2][3] = atoi(n2->created);
	newProcess[2][4] = atoi(n2->modified);
	
	newProcess[3][1] = n3->process_id;
	newProcess[3][2] = n3->length;
	newProcess[3][3] = atoi(n3->created);
	newProcess[3][4] = atoi(n3->modified);
	

	// Printing data
	for (int i = 0; i <= 3; i++){
		for (int j = 0; j <= 4; j++){
			cout << newProcess[i][j] << "\n";
		}
	}

	return 0;
}