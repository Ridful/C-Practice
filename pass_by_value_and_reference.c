#include <stdio.h>


// pass by value (just a copy)
void modify2(int x) {
    x = 42;
}

//pass by reference (able to modify the actual value)
void modify(int* x) {
    *x = 42; //Dereference pointer to modify the value
}

int main() {
    int a = 10;
    printf("a = %d\n", a);

    modify2(a); //pass a copy of a
    printf("a = %d\n", a);

    modify(&a); //pass the address of a
    printf("a = %d\n", a);

    int numbers[4] = {5,11,31,1};

    for (int i = 0; i < 4; i++) {
        printf("%d\n", numbers[i]);
    }
    printf("\n");

    modify(&numbers[0]);
    modify(&numbers[3]);

    for (int i = 0; i < 4; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}