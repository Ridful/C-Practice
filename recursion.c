#include <stdio.h>
#include <string.h>

unsigned int multiply(unsigned int x, unsigned int y) {
    if (x == 1) { return y; }
    else if (x > 1) {
        return y + multiply(x-1, y);
    }
    return 0;
}

void reverse_string(char * word) {
    if (*word == '\0') {
        return;
    }
    reverse_string(word + 1);
    putchar(*word);
}


int main() {

    printf("3 times 5 is %d\n", multiply(3, 5));

    char * word = "hello";
    reverse_string(word);
    putchar('\n');

    return 0;
}