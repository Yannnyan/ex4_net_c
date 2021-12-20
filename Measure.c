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


#define port 5050
int main(){

    char buf[256];

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

    // // set the Congestion control
    // socklen_t len;
    // len = sizeof(buf);
    // if (getsockopt(network_socket, IPPROTO_TCP, TCP_CONGESTION, buf, &len) != 0)
    // {
    //     perror("getsockopt");
    //     return -1;
    // }
    // printf("Current: %s\n", buf);
    // strcpy(buf, "reno");
    // len = strlen(buf);
    // if (setsockopt(network_socket, IPPROTO_TCP, TCP_CONGESTION, buf, len) != 0)
    // {
    //     perror("setsockopt");
    //     return -1;
    // }
    // len = sizeof(buf);
    // if (getsockopt(network_socket, IPPROTO_TCP, TCP_CONGESTION, buf, &len) != 0)
    // {
    //     perror("getsockopt");
    //     return -1;
    // }

    // printf("New: %s\n", buf);


    // if received a buf with the first spot EOF then its the end of the file
    int true = 1, counter =0;
    time_t currentTime, lastTime, dt;
    currentTime = time(NULL);
    while(true == 1){
        recv(network_socket, (char *) &buf,sizeof(buf),0);
        if(buf[0] == EOF){
            // measure time . . .
            counter +=1;
            lastTime = currentTime;
            currentTime = time(NULL);
            dt = currentTime - lastTime;
            printf("The time took for the system to recieve %d'th file is : %ld", counter, dt);    
        }
        if(counter == 5){
            true = 0;
        }
    }
    

}