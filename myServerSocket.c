#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <fcntl.h> // for open
#include <unistd.h> // for close

int main(){

    char server_message[256];


    // creating the socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    //define the server addresss
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to our specified IP and port
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    int client_socket = accept(server_socket, NULL,NULL);

    char filename[256] = "mytext.txt\0", currChar;
    FILE *text = fopen(filename, "r");
    if(text == NULL){
        printf("There is no such file");
        return 1;
    }
    int messageIndex = 0;
     currChar = fgetc(text);
     while(currChar != EOF){
        // to know that we dont exceed the message limit
        if(messageIndex == 255){
            server_message[255] = '\0';
            send(client_socket, server_message, sizeof(server_message), 0);
            messageIndex = 0;
        }
        server_message[messageIndex++] = currChar;
        currChar = fgetc(text);
    }
    server_message[messageIndex] = '\0';
    send(client_socket, server_message, sizeof(server_message), 0);
    // send ack that we finished sending messages
    server_message[0] = '\0';
    send(client_socket, server_message, sizeof(server_message), 0);
    // send(client_socket, server_message, sizeof(server_message), 0);
    // send(client_socket,server_message2,sizeof(server_message2), 0);
    // // close the socket
    close(server_socket);

    return 0;
}