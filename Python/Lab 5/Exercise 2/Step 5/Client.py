'''
Created on 15 sep. 2014

@author: Kjell
'''

from socket import *

serverName="127.0.0.1"
serverPort=12000
clientSocket=socket(AF_INET, SOCK_DGRAM)
message =input("Enter a message in upper and lower characters: ")
clientSocket.sendto(message.encode(encoding='utf_8', errors='strict'),(serverName.encode(encoding='utf_8', errors='strict'), serverPort))
modifiedMessage, serverAddress=clientSocket.recvfrom(2048)
print("Message received from server: " + str(modifiedMessage))

serverName="127.0.0.1"
serverPort=13000
clientSocket=socket(AF_INET, SOCK_DGRAM)
message =input("Enter a message in upper and lower characters: ")
clientSocket.sendto(message.encode(encoding='utf_8', errors='strict'),(serverName.encode(encoding='utf_8', errors='strict'), serverPort))
modifiedMessage, serverAddress=clientSocket.recvfrom(2048)
print("Message received from server: " + str(modifiedMessage))

clientSocket.close()

