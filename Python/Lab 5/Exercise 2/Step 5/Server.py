
'''
Created on 15 sep. 2014

@author: Kjell
'''

from socket import *
serverPort=12000
serverSocket=socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('localhost', serverPort))
print("The server is ready and waiting for clients...")
while True:
    message, clientAddress=serverSocket.recvfrom(2048)
    modifiedMessage= message
    serverSocket.sendto(modifiedMessage, clientAddress)