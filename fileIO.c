#include <stdio.h>

/*
fopen() opens file
fprintf() write formatted text to file
fscanf() read formatted input from a file
fgets() read a line from a file
fclose() close file
*/

int main() {
    FILE* fp;
    char* filename = "test.txt";

    //Open file as write
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file: \'%s\'\n", filename);
        return 1;
    }

    //Write string to file
    fprintf(fp, "This is a sample message.\n");

    //Close file
    fclose(fp);

    //Open file as read
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: \'%s\'\n", filename);
        return 1;
    }

    //Read a file
    char linebuf[100];
    fgets(linebuf, sizeof(linebuf), fp);

    //Print line from file
    printf("%s", linebuf);

    //Close file
    fclose(fp);
    return 0;
}