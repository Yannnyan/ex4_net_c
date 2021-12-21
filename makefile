
ex4: measure sender
examples: tcp_server tcp_client
tcp_server: myServerSocket.o
	gcc -g -Wall -o tcp_server myServerSocket.o
tcp_client: myClientSocket.o
	gcc -g -Wall -o tcp_client myClientSocket.o
myClientSocket.o: myClientSocket.c
	gcc -g -Wall -c myClientSocket.c
myServerSocket.o: myServerSocket.c
	gcc -g -Wall -c myServerSocket.c
measure: measure1.o
	gcc -g -Wall -o measure measure1.o
sender: sender1.o
	gcc -g -Wall -o sender sender1.o
measure1.o: measure1.c
	gcc -g -Wall -c measure1.c 
sender1.o: sender1.c
	gcc -g -Wall -c sender1.c
clean:
	rm -f *.o *.out tcp_server tcp_client measure sender