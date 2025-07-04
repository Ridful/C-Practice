#include <stdio.h>
#include <string.h>

void xor_encrypt_decrypt(char* input, char* output, char key) {
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ key;
    }

    output[len] = '\0';

}

int read_from_file(char* filename, char* text, size_t text_size) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error opening file\n");
        return 1;
    }

    //Put line from file into variable 'text'
    fgets(text, text_size, fp);

    fclose(fp);
    return 0;
}

int write_to_file(char* filename, char* text) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing\n");
        return 1;
    }

    fprintf(fp, "%s", text);
    fclose(fp);
    return 0;
}

int main() {
    char* filename = "test.txt";

    char text[100];
    char encrypted[100];
    char decrypted[100];
    char key = 'K';

    //readFromFile(&filename);
    if (read_from_file(filename, text, sizeof(text)) != 0) {
        return 1;
    }

    printf("Plaintext from file: %s\n", text);

    //Encrypt
    xor_encrypt_decrypt(text, encrypted, key);
    printf("XOR Encrypted string from file: %s\n", encrypted);

    //Decrypt
    xor_encrypt_decrypt(encrypted, decrypted, key);
    printf("XOR Decrypted string: %s\n", decrypted);

    // Write XOR Encrypted String back to file
    if (write_to_file(filename, encrypted) != 0) {
        return 1;
    }
    printf("Wrote XOR Encrypted to file\n:\"%s\"", encrypted);

    return 0;
}