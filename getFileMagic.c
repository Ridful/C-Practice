#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC_BYTES 8

int main() {

    char filepath[1024];
    unsigned char buffer[MAGIC_BYTES];

    printf("Enter file path: ");
    if (fgets(filepath, sizeof(filepath), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    // remove the newline character from fgets
    size_t len = strlen(filepath);
    if (len > 0 && filepath[len - 1] == '\n') {
        filepath[len - 1] = '\0';
    }

    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("Error, couldnt open file");
        return 1;
    }

    size_t bytesRead = fread(buffer, 1, MAGIC_BYTES, file);
    fclose(file);

    if (bytesRead == 0) {
        fprintf(stderr, "couldnt read from file or the file is empty\n");
        return 1;
    }

    printf("Magic number (first %zu bytes): ", bytesRead);
    for (size_t i = 0; i < bytesRead; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");

    // TODO - Add pattern matching for filetypes
    // possibly compare file extension with observed magic number

    return 0;
}