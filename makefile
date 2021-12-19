tcp_server: myServerSocket.o
	gcc -g -Wall -o tcp_server myServerSocket.o
tcp_client: myClientSocket.o
	gcc -g -Wall -o tcp_client myClientSocket.o
myClientSocket.o: myClientSocket.c
	gcc -g -Wall -c myClientSocket.c
myServerSocket.o: myServerSocket.c
	gcc -g -Wall -c myServerSocket.c
clean:
	rm -f *.o tcp_server tcp_client