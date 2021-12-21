#include <sys/types.h> 
#include <sys/socket.h>

#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#include <string.h>
#include <arpa/inet.h> 
#include <stdint.h>


#include <string.h>
#include <arpa/inet.h> 
#include <stdio.h>
#include <time.h>
#include <unistd.h>


#include <inttypes.h>
#include <unistd.h>

#define port 9003

int main(){
    // include timer for sending files
    // include congestion control
    // include connect host 
    
    char buf[256];
    socklen_t len;

    int network_socket= socket(AF_INET,SOCK_STREAM,0);
    if(network_socket< 0) {
    printf("Error creating socket\n");
    }
    struct sockaddr_in saddr;
    saddr.sin_family=AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port=htons(port);

    int con = connect(network_socket, (struct sockaddr *) &saddr, sizeof(saddr));
    if(con < 0 ){
        printf("cannot connect");
        return -1;
    }
    // Congestion control : 
     len=sizeof(buf);
    if(getsockopt(network_socket, IPPROTO_TCP, TCP_CONGESTION, buf, &len)!=0){
        perror("getsockopt");
        return -1;
    }
    printf("Current: %s\n", buf);

    strcpy(buf, "reno");
    len= strlen(buf);
    if(setsockopt(network_socket, IPPROTO_TCP, TCP_CONGESTION, buf, len)!=0){
        perror("setsockopt");
        return -1;
    }
    len = sizeof(buf);
    if(getsockopt(network_socket, IPPROTO_TCP, TCP_CONGESTION, buf, &len)!=0){
        perror("getsockopt");
        return -1;
    }
    printf("New: %s\n",buf);

    // sending the files
    
    // set the file
    FILE * file;
    char filename[256] = "mytext.txt";
    file = fopen(filename, "rb");
    // create buffer to send data with
    char buffer[256]; 
    time_t currentTime = time(NULL)
    , lastTime;
    while(fread(buffer, 1, sizeof(buffer), file) > 0){
        // send the buffer
        send(network_socket, buffer, sizeof(buffer), 0);
    }
    // send ack to verify one file was sent
    buffer[0] = EOF;
    send(network_socket, buffer, sizeof(buffer), 0);

    lastTime = currentTime;
    currentTime = time(NULL);
    time_t dt = currentTime - lastTime;
    printf("Operation done, time took to excecute : %ld", dt);
    fclose(file);
    close(network_socket);
}
