#include <stdio.h>
#include <stdlib.h>


// why? no full stringexists in static memory, harder to detect

int main() {

    char cmd[12]; //declare a buffer on the stack

    //build string character by character
    cmd[0] = 'n';
    cmd[1] = 'o';
    cmd[2] = 't';
    cmd[3] = 'e';
    cmd[4] = 'p';
    cmd[5] = 'a';
    cmd[6] = 'd';
    cmd[7] = '.';
    cmd[8] = 'e';
    cmd[9] = 'x';
    cmd[10] = 'e';
    cmd[11] = '\0';

    printf("Command to run: %s\n", cmd);

    int ret = system(cmd);
    printf("system() returned: %d\n", ret);

    return 0;
}