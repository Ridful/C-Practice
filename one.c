#include <stdio.h>
#include <Windows.h>
/*
*/

// Prints a line to the screen
void printLine(const char *line) {
    printf("%s\n", line);
}

int main() {

    char *message = "Welcome, what's your name?";
    char name[50];

    printLine(message);
    scanf("%s", &name);

    printf("Hello, %s!\n", name);
    // Call the printLine function with a string literal
    printLine("\nHello, world!");

    // Show a Windows message box
    MessageBoxA(NULL, "This is a Windows API MessageBox!", "Hello from Windows API", MB_OK | MB_ICONINFORMATION);

    return 0;
}