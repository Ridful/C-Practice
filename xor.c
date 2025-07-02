#include <stdio.h>
#include <string.h>

void xor_encrypt_decrypt(char *input, char *output, char key) {
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ key;
    }

    output[len] = '\0'; //null terminate the string

}

int main() {
    char text[] = "hello xor";
    char key = 'K';
    char encrypted[100];
    char decrypted[100];

    //Encrypt
    xor_encrypt_decrypt(text, encrypted, key);
    printf("Encrypted: %s\n", encrypted);

    //Decrypt
    xor_encrypt_decrypt(encrypted, decrypted, key);
    printf("Decrypted: %s\n", decrypted);


    return 0;
}