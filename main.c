#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int args, char *argv[])
{
    int wordCounter = 0;
    int buffer;
    int i,j;


    FILE *fp;

    if (args == 1){

        printf("Word Sort v1.0\n");
        printf("written by Apostolis Boutos\n");
        printf("8/8/2018\n\n\n\n");
        printf("This program sorts a list of words contained in a file separated by a new line.\n");
        printf("Drag and drop the file containing the words to be sorted on the icon of Word Sort.\n\n\n\n");
        system("PAUSE");
        return -1;

    }
    //TODO The following code checks if the user accidentally used the backup as the file to be sorted and
    //forces the program to close, because otherwise the backup will be made automatically empty.
    /*
    if (strcmp(argv[1],"backup.txt") == 0){
        system("PAUSE");
        return -1;
    }*/



    fp = fopen(argv[1],"r");

    //Count the number of words in the file.
    while((buffer = fgetc(fp)) != EOF){

        if (buffer == '\n'){
            wordCounter++;
        }
    }

    fseek(fp,0,SEEK_SET);

    //Create a table to store the words.
    char *words[wordCounter];

    //Store each word in the words table.
    for (i=0;i<wordCounter;i++)
    {
        //Count the size of the word.
        int letterCounter = 0;
        while((buffer = fgetc(fp) != '\n'))
        {
          letterCounter++;
        }
        fseek(fp,-1*letterCounter - 2,SEEK_CUR);

        words[i] = malloc(letterCounter + 1);
        //Append each character in the str buffer.
        for(j=0;j<letterCounter+1;j++){
            words[i][j] = fgetc(fp);
        }
        words[i][letterCounter] = '\0';
    }
    fclose(fp);

    //Sort the table containing the words.

    //sort();
    for (i=0;i<wordCounter;i++){

        int min = i;
        for(j=i+1;j<wordCounter;j++){

            if (strcmp(words[min],words[j]) > 0){
                min = j;
            }
        }
        char *tmp = words[min];
        words[min] = words[i];
        words[i] = tmp;
    }
    //Rename the input file into backup.txt
    remove("backup.txt");
    rename(argv[1],"backup.txt");


    //Print the sorted table in the new file.
    fp = fopen(argv[1],"w");
    for (i=0;i<wordCounter;i++){

        fputs(words[i],fp);
        fputc('\n',fp);
    }
    fclose(fp);

    for (i=0;i<wordCounter;i++){

        free(words[i]);
    }
    return 0;
}
