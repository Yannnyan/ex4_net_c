#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <fcntl.h> // for open
#include <unistd.h> // for close

int main(){
    // create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    // set port
    server_address.sin_port = htons(9002);
    // connect to any
    server_address.sin_addr.s_addr = INADDR_ANY;
    // casting server_address to a pointer, connect demands a size of the address
    // getting value 0 is ok, -1 there is an error with the connection
    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if(connection_status < 0){
        printf("There was a connection error making a connection to the remote socket\n\n");
    }
    // receive data from the server
    // the second parameter is the location of where to put the data we get back from our socket
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response),0);

    // print out the server's response
    printf("The server sent the data : %s\n", server_response);

    //and then close the socket
    close(network_socket);

    return 0;
}