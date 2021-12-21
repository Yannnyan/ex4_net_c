#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    //set the file
    char filename[256] = "mytext.txt";
    FILE *myfile = fopen(filename, "r");
    char **text;
    // init 5 rows with 256 chars
    printf("hello world\n");
    text = (char **) malloc(sizeof(char*) * 5);
    for(int i=0; i< 5; i++){
        text[i] = (char *) malloc(sizeof(char) * 256);
    }
    int numRows = 5;
    // initialization of text pointer
    char nextchar = fgetc(myfile);
    printf("initialize a 2d array\n");
    for(int j=0; nextchar != EOF; j++){
        if(j >= numRows){
            // malloc new memory
            numRows += 5;
            // allocate memmory for temp 2d array and its rows
            char **temp = (char **) malloc(sizeof(char*) * numRows);
            for(int p=0; p< numRows; p++){
                temp[p] = (char *) malloc(sizeof(char) * 256);
            }
            for(int k=0; k< numRows-5; k++){
                strcpy(temp[k],text[k]);
            }
            // free text memory and its rows
            for(int p =0; p < numRows-5; p++){
                free(text[p]);
            }
            free(text);
            text = temp;
        }
        for(int i=0; i< 256; i++){
            if(nextchar == EOF){
                text[j][i] = '\0';
                break;
            }
            if(i == 255){
                text[j][i] = '\0';
            }
            else{
            text[j][i] = nextchar;
            nextchar = fgetc(myfile);
            }
        }
    }
    for(int counter = 0; counter < 5 ; counter ++ ){
        for(int rowIndex= 0; rowIndex < numRows; rowIndex++)
        for(int i=0; i< 256; i++){
            if (text[rowIndex][i] != '\0')
                printf("%c", text[rowIndex][i]);
            else break;
        }
    }
    for(int p=0; p < numRows ; p++){
        free(text[p]);
    }
    free(text);
    return 0;
}