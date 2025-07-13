#include <stdio.h>


unsigned int multiply(unsigned int x, unsigned int y) {
    if (x == 1) { return y; }
    else if (x > 1) {
        return y + multiply(x-1, y);
    }
    return 0;
}


int main() {

    printf("3 times 5 is %d", multiply(3, 5));

    return 0;
}