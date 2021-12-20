#include <sys/types.h> 
#include <sys/socket.h>

#include <string.h>
#include <arpa/inet.h> 
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdint.h>
#include <inttypes.h>

#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define port 5050
int main(){
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock <0){
        printf("failed opening socket");
        return -1;
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int b = bind(sock,(struct sockaddr *) &server_address,sizeof(server_address));
    if(b <0){
        printf("failed to bind the socket to the address");
        return -1;
    }
    int l = listen(sock,5);
    if(l < 0){
        printf("failed to listen");
        return -1;
    }
    int Measure_socket = accept(sock, NULL,NULL);
    // // set the Congestion control
    // char buf[256];
    // socklen_t len;
    // len = sizeof(buf);
    // if (getsockopt(sock, IPPROTO_TCP, TCP_CONGESTION, buf, &len) != 0)
    // {
    //     perror("getsockopt");
    //     return -1;
    // }
    // printf("Current: %s\n", buf);
    // strcpy(buf, "reno");
    // len = strlen(buf);
    // if (setsockopt(sock, IPPROTO_TCP, TCP_CONGESTION, buf, len) != 0)
    // {
    //     perror("setsockopt");
    //     return -1;
    // }
    // len = sizeof(buf);
    // if (getsockopt(sock, IPPROTO_TCP, TCP_CONGESTION, buf, &len) != 0)
    // {
    //     perror("getsockopt");
    //     return -1;
    // }

    // printf("New: %s\n", buf);

    char filename[256] = "mytext.txt";
    FILE *myfile = fopen(filename, "r");
    char **text;
    // init 5 rows with 256 chars
    text = (char **) malloc(sizeof(char*) * 5);
    for(int i=0; i< 5; i++){
        text[i] = (char *) malloc(sizeof(char) * 256);
    }
    int numRows = 5;
    // initialization of text pointer
    char nextchar = fgetc(myfile);
    for(int j=0; nextchar != EOF; j++){
        if(j >= numRows){
            // malloc new memory
            numRows += 5;
            char **temp = (char **) malloc(sizeof(char*) * numRows);
            for(int k=0; k< numRows-5; k++){
                strcpy(temp[k],text[k]);
            }
            free(text);
            text = temp;
        }
        for(int i=0; i< 256; i++){
            text[j][i] = nextchar;
            nextchar = fgetc(myfile);
        }
    }
    char FileDone[256];
    FileDone[0] = EOF ;
    // send the file 5 times
    for(int i = 0; i < 5; i++){
        for(int j=0; j < numRows; j++){
            send(Measure_socket,(char *) &text[j], sizeof(text[j]), 0);
        }
        send(Measure_socket,(char *)&FileDone, sizeof(FileDone),0);
    }
    // change CC

    // send the file 5 times
}