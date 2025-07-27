#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define MIN_STRING_LENGTH 4

int main() {

    char filepath[1024];

    printf("Enter file path: ");

    if (fgets(filepath, sizeof(filepath), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    size_t len = strlen(filepath);
    if (len > 0 && filepath[len - 1] == '\n') {
        filepath[len - 1] = '\0';
    }

    FILE * fp = fopen(filepath, "rb");
    if (!fp) {
        perror("Error couldnt open file");
        return 1;
    }

    char buffer[BUFSIZ];
    char stringBuffer[BUFSIZ];
    size_t strIndex = 0;

    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (isprint(c)) { //check if c is printable
            if (strIndex < sizeof(stringBuffer) - 1) {
                stringBuffer[strIndex++] = c;
            }
        } else {
            if (strIndex >= MIN_STRING_LENGTH) {
                stringBuffer[strIndex] = '\0';
                printf("%s\n", stringBuffer);
            }
            strIndex = 0;
        }
    }

    if (strIndex >= MIN_STRING_LENGTH) {
        stringBuffer[strIndex] = '\0';
        printf("%s\n", stringBuffer);
    }
    fclose(fp);

    return 0;
}