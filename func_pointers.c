#include <stdio.h>



int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

int sub(int a, int b) { return a - b; }


int main() {

    int (*func_ptr)(int, int); //declare a pointer to a function taking (int, int) and returning int
    func_ptr = add;

    int result = func_ptr(1,2);
    printf("Result: %d\n", result);

    func_ptr = mul;
    printf("Multiply Result: %d\n", func_ptr(2,3));

    int (*ops[3])(int, int); //array of 2 function pointers
    ops[0] = add;
    ops[1] = sub;
    ops[2] = mul;

    printf("Add: %d\n", ops[0](10, 5));
    printf("Sub: %d\n", ops[1](10, 5));
    printf("Mul: %d\n", ops[2](10, 5));

    return 0;
}