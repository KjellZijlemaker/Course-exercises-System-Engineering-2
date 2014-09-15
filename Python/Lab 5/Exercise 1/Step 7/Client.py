'''
Created on 15 sep. 2014

@author: Kjell
'''

from socket import *

serverName="127.0.0.1"
serverPort=12000
clientSocket=socket(AF_INET, SOCK_DGRAM)
firstNumber=input("Enter the first number: ")
secondNumber=input("Enter the second number: ")
clientSocket.sendto(firstNumber.encode(encoding='utf_8', errors='strict'),(serverName.encode(encoding='utf_8', errors='strict'), serverPort))
clientSocket.sendto(secondNumber.encode(encoding='utf_8', errors='strict'),(serverName.encode(encoding='utf_8', errors='strict'), serverPort))

modifiedMessage, serverAddress=clientSocket.recvfrom(2048)
print("Message received from server: "+str(modifiedMessage))

