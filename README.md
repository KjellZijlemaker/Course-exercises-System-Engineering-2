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
- Look at the server / client code for the code itself
