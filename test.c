#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *file;
    char filename[256] = "mytext.txt";
    file = fopen(filename, "r");
    char ** text = (char **) malloc(sizeof(char*) *5);
    for(int i=0; i< 5; i++){
        text[i] = (char *) malloc(sizeof(char) * 256);
    }
    char nextChar = fgetc(file);
    char message[256];
    while(nextChar != EOF){

        for(int i = 0; nextChar != EOF && i < 256; i++){
            message[i] = nextChar;
            nextChar = fgetc(file);
        }


    }



    return 0;
}