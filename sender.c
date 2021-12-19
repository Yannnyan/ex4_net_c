#include <sys/types.h> 
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h> 
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include <netdb.h>
#include <netinet/in.h>


int main(){
    // 
    struct sockaddr_in saddr;
    struct hostent *h;
    int sockfd;
    int connfd;
    unsigned short port= 5050;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    h = gethostbyname("127.0.0.1");
    memset(&saddr,'\0',sizeof(saddr));
    saddr.sin_family=AF_INET;
    memccpy((char *) &saddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
    saddr.sin_port=htons(port);
    connfd=connect(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));
    

}