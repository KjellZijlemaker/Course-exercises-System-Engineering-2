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
	createProcesses();
	printProcesses();
	
	return 0;
}

// Creating the new processes
void createProcesses(){
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
}


// Printing the processes
void printProcesses(){
	str_process *p_current = nextProcess;
	int number = 0;

	/* While the current pointer to the nextProcess is not NULL, it will run the while loop
	   and iterate through all the data types, from every process.
	*/
	while (p_current != NULL){

		// Creating the needed ints and chars
		int process_id = p_current->process_id;
		int length = p_current->length;
		char* created = p_current->created;
		char* modified = p_current->modified;

		// Printing processes out to command line
		cout << "\nThis is processID: " << p_current->process_id << "\n";
		cout << "It has the length: " << p_current->length << "\n";
		cout << "It was created on: " << p_current->created << "\n";
		cout << "It was modified on: " << p_current->modified << "\n";

		// Number for file count
		number++;

		// Calling the binaryFile method
		writeBinaryFile(process_id, length, created, modified, number);

		// Pointer will be set to the next pointer in the struct
		p_current = p_current->next;
	}

}

// Opening and appending the data to the binary file
void writeBinaryFile(int &process, int &length, char *created, char *modified, int &number){
	ofstream newFile("Result.bin", ios::out | ios::binary | std::ios::app);
	newFile.write(reinterpret_cast<const char *> (&process), sizeof(process));
	newFile.write(reinterpret_cast<const char *> (&length), sizeof(length));
	newFile.write(created, sizeof(created));
	newFile.write(modified, sizeof(modified));

	newFile.close();
	cout << "File " << number << " is done\n";
	
}
