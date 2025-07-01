#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int age;
} Person;

int main() {

    enum Day {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

    enum Day today = WEDNESDAY;

    if (today == WEDNESDAY) {
        printf("it's wednesday\n");
    }

    enum Status { OK = 200, ERROR = 500, NOT_FOUND = 404};

    enum Status curr = OK;
    printf("%d\n", curr);
    if (curr == OK) {
        printf("OK - Worked.\n");
    }
    else if (curr == ERROR) {
        printf("An Error has occurred.\n");
    }
    else if (curr = NOT_FOUND) {
        printf("Not Found\n");
    }

    Person p;

    // Set name using strcpy since name is a char array. Cant assign to arrays directly in C
    strcpy(p.name, "Alice");

    p.age = 5;

    printf("%s is %d years old\n", p.name, p.age);

    return 0;
}