#include <sys/types.h> 
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h> 
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>


int main(){
    int sockfd= socket(AF_INET,SOCK_STREAM,0);
    int clen;
    struct sockaddr_in saddr,caddr;
    unsigned short port =5050;
    if(sockfd< 0) {
    printf("Error creating socket\n");
    }
    memset(&saddr, '\0', sizeof(saddr));
    saddr.sin_family=AF_INET;
    saddr.sin_addr.s_addr=htonl(INADDR_ANY);
    saddr.sin_port=htons(port);
    if(bind(sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0) {
    printf("Error binding\n");
    }
    listen(sockfd,5);
    clen=sizeof(caddr);

    int isock=accept(sockfd, (struct sockaddr_in *) &caddr, &clen);
    recv(AF_INET,,sizeof,)

}