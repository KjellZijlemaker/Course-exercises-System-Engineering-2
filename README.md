Course exersizes System Engineering 2
===============

This repo includes all exersizes from System Engineering 2



#Python weetjes

- Indien er een klasse aangemaakt wordt, dan moet deze altijd de klassenaam bevatten. Een constructor mag
- Indien je een klasse instantieerd, zorg ervoor dat je het bestand importeert, zoals: import SecondScript. Hierna instanteer je doormiddel van: SecondScript.SecondScript()
- In een klasse dien je altijd bij functions de (self) parameter mee te geven!!!
- Aan het begin van elke script vul je: #! /usr/bin/python in!
- Indien je een main functie hebt, roep deze aan doormiddel van: if__name__ == "__main__": main()



#C++ weetjes

- Je begint altijd met: using namespace: std
- Met #inlcudes kun je verschillende modules toevoegen
- Pointers maak je aan doormiddel met: int *kjell; en wijs je toe aan een andere int: *kjell = j;
- Een referentie maak je aan doormiddel met: int &kjell; en wijs je toe met een andere int: &kjell = j;
- Referenties en pointers wijzen naar een stuk geheugen
- Het verschil tussen een referentie en een pointer is dat een pointer van geheugen kan veranderen, meer eigenlijk niet
- Je kan met referenties en pointers combineren, bijvoorbeeld in een functie
- Met enums is het mogelijk om getallen om te zetten naar letters, zodat deze gemakkelijk te lezen zijn in functies. Bijvoorbeeld:

````c++
// Geeft enum LOLLIKLOP met een waarde 1, maar is gemmakelijker te lezen voor een programmeur.
enum TestCase {LOLLIEPOP, LOLLIKLOP};

if(eten == LOLLIKLOP){
  Doe iets
}
```

#Interprocess networking communication facts

- In higher level languages like Pyhon or Java, you don't need to do all the underlying functions for making a correct TCP/IP connection
- You can use IPV4 and IPV6. Mostly you will use IPV4.
  - You can use IPV4 with ````AF_INET````
- You can make TCP connections for stream oriented (reliable) connections, or UDP for datagram (unreliable) data connections.
  - For the TCP connections you mostly use: ```SOCK_STREAM```
  - For UDP connections you mostly use: ````SOCK_DGRAM````
- A server must always be in a unlimited while (or for) loop for connecting to other sockets
- Servers can be code independent
- Look in the book for more interesting facts


# Special for Lab8
## Good link for example code: http://ilab.cs.byu.edu/python/select/echoserver.html
## Clientpart
- When created a socket with the code ````s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)```` u can use the reference s for connecting to the server ````s.connect()````
- With the above code, you can also send the message with ````s.send()````
- To get the data (mostly it it will be encoded), use the ````data = s.recv(1024)````. This is the total data buffer the variable can hold
- To decode data (and modify it), use the ````ModifiedString = data.decode('utf-8')```` command
- ````client.setblocking(0)```` is for disabling the blocking on the socket, so other clients can also connect and do not have to wait

##Serverpart
- ````server.listen()```` is for giving the max connections in the server
- ````server.setblocking(0)```` is for disabling the blocking on the server socket so other clients can connect
- The server mostly has 3 arrays: one for the input, output and for queuing the messages. There also can be a third array for queuing the exceptions
- To automate the queues that need to queue, there’s the ````select.select(input, outputs, inputs)```` command. This command is to efficiently wait for all the input and get the output from other clients
- It’s important to give the connection inside the message queue a new queue for handling all the data. This is done like this: ````message_queues[connection] = Queue.Queue()````
- Like the client, data needs to be received from the client with the recv method
- Data needs to get into the message queue before moved to handle the output of course. Be careful with making the queues, it’s very important that messages, and output queues will be emptied when done
- Code like underneath will take care that new clients will be accepted by the server. Also, the input array (from the select) will be appended with the client. When it will be called again, the response can been given. 
````Python
if s == server: 
    # handle the server socket 
    client, address = server.accept() 
    input.append(client)
````
- Look at the server / client code for the code itself


#Lab 9 JAVA
## Threads

- You can make Threads with either extending the Thread class, or to implement Runnable.
  - Mostly, implementing the Runnable is the most common
  - When doing more complex stuff with more threads (pool for example), extending the Thread class is more useful
- Starting a Thread is very different than starting Threads in Pyhthon.
  - Starting a Thread with the Runnable interface: 
    - ````
      Runnable hello = new DisplayMessage("Hello");
      Thread thread1 = new Thread(hello);
      thread1.setDaemon(true);
      thread1.setName("hello");
      System.out.println("Starting hello thread...");
      thread1.start(); ````
  - Starting a Thread with extending the Thread class:
    - ````
      System.out.println("Starting thread3...");
      Thread thread3 = new GuessANumber(27);
      thread3.start();
      `````

## Mutual exclusion
- In Java, you have the ````synchronized ```` keyword
  - The keyword can be used with methods and blocks of code
  - The object inside the keyword will serve as the monitor object and may not be used by another thread for execution, when already used


## Semaphores
- Java already implements Semaphores in the concurrent package, but you can make your own implementation
- There are 3 kinds of Semaphores
  - Simple Semaphore
    - Thread can take and release the Semaphore, other Threads must wait when taken
  - Counting Semaphore
    - Thread can take and release the Semaphore, the Semaphore count will increment when taken for an indication of Threads that want to take the Semaphore
  - Bounded Semaphore
    - Most widely used for Threads that will take and release the Semaphore. Acts like the counting Semaphore, but will also have a boundary for how many Threads there can go into the critical section
- Mostly, Semaphores will be used as Locks with bounded Semaphores. Below, an implemantation is given:
````
BoundedSemaphore semaphore = new BoundedSemaphore(1);

...

semaphore.take();

try{
  //critical section
} finally {
  semaphore.release();
}
````


## Networking
- In java, networking with sockets is fairly simple
  - In the Java networking API, there is the Socket's and the ServerSocket's family to make connections through the network
- TCP and UDP in Java exist
  - TCP is a stream connection that is reliable
  - UDP is a packet connection that is not reliable, but has less overhead then TCP
    - UDP uses DatagramSocket's

### Client
- The client has to make use from the Socket's API
- The init for the Socket will need the hostname (or IP) and the port where it will connect through
- You have the inputstream for input
````
Socket socket = new Socket("jenkov.com", 80);
InputStream in = socket.getInputStream();

int data = in.read();
//... read more data...

in.close();
socket.close();
````
- You have the outputStream for the ouput
````
Socket socket = new Socket("jenkov.com", 80);
OutputStream out = socket.getOutputStream();

out.write("some data".getBytes());
out.flush();
out.close();

socket.close();
````
- You will first need to close the input or outputStream and then close the socket itself when done

### Server
- The server will make use from the ServerSocket's API
- The init for the Socket will be the port on which it will run
  - The port will be the listening port for incoming connections
  - It will need to go through a while loop until it will have a connection
- When connection has accourt, a new ClientSocket will be made and connected with the ServerSocket's connection, with the accept() method
````
ServerSocket serverSocket = new ServerSocket(9000);

boolean isStopped = false;
while(!isStopped){
    Socket clientSocket = serverSocket.accept();

    //do something with clientSocket
}
````
- The clientSocket will need to close when done, with the clientSocket.close() method
- At last the ServerSocket will need to close with the serverSocket.close() method, only when really shutting down the server!
````
clientSocket.close()
serverSocket.close()
````


### UDP packets (harder than TCP)
- The server does not know what it will receive and when it will receive
- The client does not know what it will receive and when it will receive
- UPD packets are connectionless and will have no confirmations
- Sending UDP data from a server will be like this:
````
byte[] buffer = new byte[65508]; // Array for each packet (buffer)
InetAddress address = InetAddress.getByName("jenkov.com"); // The address in bytes

/**
* The packet will consist of the buffer (packet), the length of the buffer, the address in bytes and the port it will need to 
* be send through
* /
DatagramPacket packet = new DatagramPacket(
    buffer, buffer.length, address, 9000);
````
- Receiving will be like this:
````
DatagramSocket datagramSocket = new DatagramSocket(80); // Making new socket on port 80 to listen on

// Byte array for the receiving packets
byte[] buffer = new byte[10];

/**
* The packet init for the DatagramPacket will now be the buffer and the length of the buffer
*/
DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

// It will now receive the packet
datagramSocket.receive(packet);

// Data can get in the buffer for extracting data
byte[] buffer = packet.getData();
````
- TCP and UDP port 80 for example, are not the same! When TCP is in use, the UDP version can still be used on the same port
