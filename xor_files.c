#include <stdio.h>
#include <string.h>

void readFromFile(char* filename) {
    
}

void xor_encrypt_decrypt(char* input, char* output, char key) {
    int len = sizeof(input);

    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ key;
    }

    output[len] = '\0';

}


int main() {
    FILE* fp;
    
    char* filename = "test.txt";

    char text[100];
    char encrypted[100];
    char decrypted[100];
    char key = 'K';
    //readFromFile(&filename);

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error opening file");
        return 1;
    }

    //Put line from file into variable 'text'
    fgets(text, sizeof(text), fp);

    printf("Plaintext from file: %s\n", text);

    fclose(fp);

    xor_encrypt_decrypt(text, encrypted, key);
    printf("XOR Encrypted string from file: %s\n", encrypted);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file");
        return 1;
    }

    printf("Writing text to file: %s\n", encrypted);
    fprintf(fp, text);

    fclose(fp);



    return 0;
}