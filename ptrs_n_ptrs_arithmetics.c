#include <stdio.h>


//*p means "value at"
//&x means "address of"

//When you do `ptr + 1`, you're actually moving forward by sizeof(type) bytes.

//p[2] means *(p+2)

// *(p+1)  =  Get the value at the address p+1

int main() {

    // Basic Pointers
    int a = 5;
    int* p = &a; //&a is the address of a,  *p is the value stored at the address p points to (5)
    printf("%d\n", *p);

    *p = 20;
    printf("%d\n", *p);


    //Basic Pointer Arithmetic

    int arr[] = {10,20,30};
    int* ptr = arr;

    printf("%d\n", *(ptr));
    printf("%d\n", *(ptr + 1));
    printf("%d\n", *(ptr + 2));

    return 0;
}