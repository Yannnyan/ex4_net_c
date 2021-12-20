ex4: Measure sender
examples: tcp_server tcp_client
tcp_server: myServerSocket.o
	gcc -g -Wall -o tcp_server myServerSocket.o
tcp_client: myClientSocket.o
	gcc -g -Wall -o tcp_client myClientSocket.o
myClientSocket.o: myClientSocket.c
	gcc -g -Wall -c myClientSocket.c
myServerSocket.o: myServerSocket.c
	gcc -g -Wall -c myServerSocket.c
Measure: Measure.o
	gcc -g -Wall -o Measure Measure.o
sender: sender.o
	gcc -g -Wall -o sender sender.o
Measure.o: Measure.c
	gcc -g -Wall -c Measure.c 
sender.o: sender.c
	gcc -g -Wall -c sender.c
clean:
	rm -f *.o tcp_server tcp_client Measure sender