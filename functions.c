#include "functions.h"
#include <stdlib.h>

 char * getFilenameFromPath(const char * path){

    int pathCharCounter = 0;
    int filenameCharCounter = 0;
    int i;

    //Count the number of characters the path contains.
    while (path[pathCharCounter] != '\0'){
        pathCharCounter++;
    }

    //Count the number of characters the filename contains.
    i = pathCharCounter - 1;
    while (path[i] != '\\'){
        i--;
        filenameCharCounter++;
    }

    char * buffer = (char *)malloc(sizeof(char) * filenameCharCounter + 1);

    //Copy the path substring containing the filename into the buffer;
    for (i=pathCharCounter-filenameCharCounter;i<pathCharCounter;i++){

        buffer[i - (pathCharCounter - filenameCharCounter)] = path[i];
    }
    buffer[filenameCharCounter] = '\0';
    return buffer;
}



int numberOfWordsInFile(FILE * file){

    int counter = 0;
    int buffer;

    while((buffer = fgetc(file)) != EOF){

        if (buffer == '\n'){
            counter++;
        }
    }
    fseek(file,0,SEEK_SET);
    return counter;
}







