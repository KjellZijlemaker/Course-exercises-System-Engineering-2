'''
Created on 5 okt. 2014

@author: kjellzijlemaker
'''
import socket
import sys
class MyClient():
    
    def setClient(self):
        message = raw_input('Please enter a message: ')
        server_address = ('localhost', 10000)
        
        #Create TCP/IP socket
        socks = [socket.socket(socket.AF_INET, socket.SOCK_STREAM),
                 socket.socket(socket.AF_INET, socket.SOCK_STREAM),
                  socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                 ]
        
        #Connect the socket to the port of the server listening
        print >>sys.stderr, 'connectiong port %s port %s' % server_address
        for s in socks:
            s.connect(server_address)
        
        self.sendMessage(message, server_address, socks)
    
    def sendMessage(self, message, server_address, socks): 
            #Sending the message on both sockets
            for s in socks:
                print >>sys.stderr, '%s: sending "%s"' % (s.getsockname(), message)
                s.send(message)
            
            #Read responses on both sockets
            for s in socks:
                data = s.recv(1024)
                print >>sys.stderr, '%s: received "%s"' % (s.getsockname(), data)
                if not data:
                    print >>sys.stderr, 'closing socket', s.getsockname()
                    s.close()
                    
Client = MyClient()
Client.setClient()
    