#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC_BYTES 8

typedef struct {
    const char *type;
    const unsigned char *magic;
    size_t length;
} MagicPattern;

MagicPattern patterns[] = {
    {"JPEG image", (unsigned char *)"\xFF\xD8\xFF", 3},
    {"PNG image", (unsigned char *)"\x89\x50\x4E\x47\x0D\x0A\x1A\x0A", 8},
    {"GIF image", (unsigned char *)"GIF89a", 6},
    {"GIF image", (unsigned char *)"GIF87a", 6},
    {"Windows EXE", (unsigned char *)"\x4D\x5A", 2},
};

size_t patternCount = sizeof(patterns) / sizeof(MagicPattern);

// Get the file type from magic bytes
const char* get_file_type(unsigned char *buffer, size_t bytesRead) {
    for (size_t i = 0; i < patternCount; i++) {
        if (bytesRead >= patterns[i].length &&
            memcmp(buffer, patterns[i].magic, patterns[i].length) == 0) {
            return patterns[i].type;
        }
    }
    return "Unknown file type";
}

// Gets the file extension from user inputed filepath
// returns pointer to after last occurance of dot
const char* getFileExtension(const char *filepath) {
    const char *dot = strrchr(filepath, '.'); // find last occurance of (.)

    if (!dot || dot == filepath) {
        return "";
    }
    return dot + 1; //returns pointer to after dot
}

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

    const char *type = get_file_type(buffer, bytesRead);
    printf("Detected file type: %s\n", type);

    //remove newline character from fgets
    const char *ext = getFileExtension(filepath);
    if (strlen(ext) == 0) {
        printf("No file extension found.\n");
    } else {
        printf("File extension: %s\n", ext);
    }
    
    return 0;
}