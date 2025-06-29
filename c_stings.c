#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//char idk[] = "hello";  allocates 6 bytes on stack, modifiable copy on stack
//char* idk = "hello;"  points to string literal, immutable

/*
strlen(str)  length of string (excluding \0)
strcpy(dst, src)  copy string (dangerous if not enough space)
strcat(dst, src)  concatenate
strcmp(a, b)  compare strings (returns 0 if equal)
*/

int main() {
    //char* name = malloc(100 * sizeof(char));

    char name[100];
    strcpy(name, "Alice");

    printf("%d\n", strlen(name));
    printf("%s\n", name);

    char name2[] = "Alice";
    if (strcmp(name, name2)) {
        printf("%s and %s do not match\n", name, name2);
    } else {
        printf("%s and %s are matching\n", name, name2);
    }

    char sentence[100];
    strcpy(sentence, name);
    strcat(sentence, " Smith");
    printf("%s\n", sentence);

    return 0;
}