/*
 * Client.cpp
 *
 *  Created on: 20 sep. 2014
 *      Author: kjell
 */

#include "Client.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {

	if (argc < 3 || argc > 4){ // Test for correct number of arguments
		DieWithUserMessage("parameter(s)",
				"<Localhost?> <WORD> <13000>");
	}

	char *servIP = argv[1]; 	// Server IP address
	char *echoString = argv[2]; // Second arg for string to echo

	// Third arg (optional for the server port)
	in_port_t servPort = (argc == 4) ? atoi(argv[3]) : 7;

	// Create reliable stream socket with using TCP
	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock < 0){
		DieWithSystemMessage("socket() failed");
	}

	//Construct the server address structure
	struct sockaddr_in servAddr; 			// This is the server address
	memset(&servAddr, 0, sizeof(servAddr)); // Zero out the struct
	servAddr.sin_family = AF_INET;			// IPv4 address family (otherwise it will not understand..)

	// Convert address
	int rtnVal = inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr);
	if(rtnVal == 0){
		DieWithSystemMessage("inet_pton() failed", "Invalid address..");
	}
	else if(rtnVal < 0){
		DieWithSystemMessage("inet_pton() failed");
	}
	servAddr.sin_port = htons(servPort); // Serverport

	// Establish connection to echo server
	if (connect(sock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0){
		DieWithSystemMessage("connect() failed");
	}

	size_t echoStringLen = strlen(echoString); // Determine input length

	// Send string to server
	ssize_t numBytes = send(sock, echoString, echoStringLen, 0);

	if(numBytes < 0){
		DieWithSystemMessage("send() failed");
	}
	else if(numBytes != echoStringLen){
		DieWithUserMessage("send()", "sent unexpected number of bytes");
	}

	// Receive the same string back from server..
	unsigned int totalBytesRcvd = 0;		// Total bytes received (count)
	fputs("Received: ", stdout);			// Setup to print to echoed string
	while(totalBytesRcvd < echoStringLen){
		char buffer[20];					// IO buffer

		// Receive buffer size minus 1 for NULL terminator
		numBytes = recv(sock, buffer, 20 -1, 0);
		if(numBytes < 0){
			DieWithUserMessage("recv() failed");
		}
		else if(numBytes == 0){
			DieWithUserMessage("recv()", "connection closed prematurely");
		}
		totalBytesRcvd += numBytes; 		// Keep total of the bytes
		buffer[numBytes] = '\0';			// Terminate String
		fputs(buffer, stdout);				// Print the echo buffer
	}

	fputc('\n', stdout); // Print final linefeed!

	close(sock); 		// When done, close and terminate everything
	exit(0);
}

