#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int main(){

    FILE * file;
    char filename[256] = "mytext.txt";
    file = fopen(filename, "rb");
    char buffer[256]; 
    while(fread(buffer, 1, sizeof(buffer), file) > 0){
        printf("%s", buffer);
    }

}