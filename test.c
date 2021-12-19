#include <stdio.h>
#include <stdlib.h>


int main(){

    char server_message[256], currChar;
    char filename[] = "mytext.txt\0";
    FILE * file = fopen(filename, "r");
    currChar = fgetc(file);
    int messageIndex=0;
    while(currChar != EOF){
        // to know that we dont exceed the message limit
        server_message[messageIndex++] = currChar;
        currChar = fgetc(file);
    }
    server_message[messageIndex] = '\0';
    printf("%s", server_message);
    return 0;
}