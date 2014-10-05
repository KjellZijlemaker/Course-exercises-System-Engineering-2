'''
Created on 5 okt. 2014

@author: kjellzijlemaker
'''
import select
import socket
import sys
import Queue

class MyServer():
    def __init__(self):
        self.setServer()
    
    def setServer(self):
        # Create TCP/IP socket
        server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server.setblocking(0)

        # Bind te socket to port
        server_address = ('localhost', 10000)
        print >>sys.stderr, 'starting up on %s port %s' % server_address
        server.bind(server_address)

        #listening for incoming connections (max)
        server.listen(5)
        
        # Sockets from where we will read
        inputs = [server]
        
        # Sockets from where we will write
        outputs = []
        
        #Outgoing message queue
        message_queus = {}
        
        self.handleInputs(inputs, outputs, message_queus, server)
        
    def handleInputs(self, inputs, outputs, message_queues, server):
        while inputs:
            
            #Wait for one of the sockets for ready to process
            print >>sys.stderr, '\n waiting for the next event'
            readable, writable, exceptional = select.select(inputs, outputs, inputs)
            
            
            # Handle the inputs
            for s in readable:
                if s is server:
                    # Ready to accept a connection
                    connection, client_address = s.accept()
                    print >>sys.stderr, 'New connection from: ', client_address
                    connection.setblocking(0)
                    inputs.append(connection)
                    
                    #Give connecion a queue for data we want to read
                    message_queues[connection] = Queue.Queue()
                    
                else:
                    data = s.recv(1024)
                    if data:
                        #Readable client socket has data
                        print >>sys.stderr, 'Received "%s" from %s' % (data, s.getpeername())
                        
                        
                        ModifiedString = data.decode('utf-8') + " sukkel"
                        ModifiedString.encode()
                        
                        message_queues[s].put(ModifiedString)
                        
                        #Add output channel for response
                        if s not in outputs:
                            outputs.append(s)
                    else:
                        #Interpret empty result as colse connection
                        print >>sys.stderr, 'Closing', client_address, 'after reading no data'
                            
                        #Stop listening for input on the connection
                        if s in outputs:
                            outputs.remove(s)
                        inputs.remove(s)
                        s.close()
                            
                        #Remove message from queue
                        del message_queues[s]
                            
            self.handleOutputs(inputs, outputs, message_queues, server, exceptional, writable)
                            
    def handleOutputs(self, inputs, outputs, message_queues, server, exeptional, writable):
            #Handle outputs
            for s in writable:
                try:
                    next_msg = message_queues[s].get_nowait()
                except Queue.Empty:
                    #No messages waiting, so stop trying
                    print >>sys.stderr, 'output queue for', s.getpeername(), 'is empty'
                    outputs.remove(s)
                else:
                    print >>sys.stderr, 'sending "%s" to %s' % (next_msg, s.getpeername())
                    s.send(next_msg)
            
            self.handleExceptions(inputs, outputs, message_queues, server, exeptional, writable)
            
    def handleExceptions(self, inputs, outputs, message_queues, server, exceptional, writable):
            #Handle the exception conditions
            for s in exceptional:
                print >>sys.stderr, 'handling exceptional condition for', s.getpeername()
                
                #Stop listening for input connections
                inputs.remove(s)
                if s in outputs:
                    outputs.remove(s)
                s.close()
                
                #Remove the whole queue
                del message_queues[s]
                

run = MyServer()   
            
            