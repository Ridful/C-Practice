#include <stdio.h>
#include <stdlib.h>


// You cant change a pointer's value from inside a function unless you pass a pointer to it.

void allocate(int **p) {
    *p = malloc(sizeof(int));
    **p = 99;
}

int main() {

    int *ptr = NULL;
    allocate(&ptr); // We pass &ptr, so allocate() can assign to it using *p.
    
    printf("%d\n", *ptr);
    free(ptr);

    int value = 42;
    int *vptr = &value;
    int **ptr_to_ptr = &vptr;

    printf("%d\n", value);
    printf("%d\n", *vptr);
    printf("%d\n", **ptr_to_ptr);
    return 0;
}