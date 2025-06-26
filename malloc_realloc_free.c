#include <stdio.h>
#include <stdlib.h>

int main() {

    // allocate 3 ints size in memory
    int* numbers = malloc(3 * sizeof(int));
    if (numbers == NULL) { printf("Allocation failed\n"); exit(1);}

    numbers[0] = 5;
    numbers[1] = 12;
    numbers[2] = 3;

    for (int i = 0; i < 3; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // reallocate numbers to 5 ints in size in memory
    numbers = realloc(numbers, 5 * sizeof(int));
    if (numbers == NULL) { printf("Reallocation failed\n"); exit(1);}

    numbers[3] = 11;
    numbers[4] = 30;

    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
    return 0;
}