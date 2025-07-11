#include <stdio.h>

void print_bytes(const char *str) {

    for (size_t i = 0; str[i] != '\0'; i++) {
        // Print the byte value in hex
        printf("Byte %zu: 0x%02X (%c)\n", i, (unsigned char)str[i], str[i]);
        
    }
}

int main() {

    const char *my_string = "lorem ipsum";
    print_bytes(my_string);
    
    return 0;
}
