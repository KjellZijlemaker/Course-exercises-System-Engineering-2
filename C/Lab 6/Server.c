/*
 * Client.c
 *
 *  Created on: 20 sep. 2014
 *      Author: kjell
 */

#include "Server.h">
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

static const int MAXPENDING = 5;
void HandleTCPClient(int);

int main(int argc, char **argv) {
	if(argc != 2){ // Test for arguments
		DieWithUserMessage("Parameter(s)", "13000");
	}

	// Create socket
	int servSock; // Socket for descriptor
	if((servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
		DieWithSystemMessage("socket() failed");
	}

	// Construct the local address
	struct sockaddr_in servAddr; 					// Local addr
	memset(&servAddr, 0, sizeof(servAddr)); 		// Zero out struct
	servAddr.sin_family = AF_INET; 					// IPv4 address
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY); 	// Any incoming interface
	servAddr.sin_port = htons(13000); 				// Local port

	// Bind to local address
	if(bind(servSock, (struct sockaddr*) &servAddr, sizeof(servAddr))< 0){
		DieWithSystemMessage("bind() failed");
	}

	// Mark the socket so it will listen for incoming conn
	if(listen(servSock, MAXPENDING) < 0){
		DieWithSystemMessage("listen() failed");
	}

	// Running the server for listening
	for(;;){
		struct sockaddr_in clntAddr; 				// Struct for client address
		socklen_t clntAddrLen = sizeof(clntAddr);	//Length of client address structure

		// Wait for client to connect
		int clntSock = accept(servSock, (struct sockaddr *) &clntAddr, &clntAddrLen);
		if(clntSock < 0){	// If clients socket is nog right
			DieWithSystemMessage("accept() failed");
		}

		// Socket is connected:
		char clntName[INET_ADDRSTRLEN]; // Contains client address

		// Making connection and if connected, handling client
		if(inet_ntop(AF_INET, &clntAddr.sin_addr.s_addr, clntName, sizeof(clntName))!= NULL){
			printf(" Handling client %s/%d\n", clntName, ntohs(clntAddr.sin_port)); // Converting address
		}
		else{
			puts(" Unable to get Client address");
		}
		HandleTCPClient(clntSock);
	}
	// Never ending story
}

void HandleTCPClient(int clntSocket){
	char buffer[20]; // For echoing String

	// Receive message from client
	ssize_t numBytesRcvd = recv(clntSocket, buffer, 20, 0);
	if(numBytesRcvd < 0){
		DieWithSystemMessage("recv() failed");
	}

	// Send received String and receive again
	while(numBytesRcvd > 0){ // If end of stream

		// Echo message to client
		ssize_t numBytesSent = send(clntSocket, buffer, numBytesRcvd, 0);

		if (numBytesSent < 0) {
			DieWithSystemMessage("send() failed");
		}
		else if(numBytesSent != numBytesRcvd){
			DieWithUserMessage("send()", "sent unexpected number of bytes");
		}

		// See if there is more data..
		numBytesRcvd = recv(clntSocket, buffer, 20, 0);
		if(numBytesRcvd < 0){
			DieWithSystemMessage("recv() failed");
		}

		close(clntSocket); // Close and kill the whole socket
	}
}
