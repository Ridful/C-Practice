#include <stdio.h>
#include <Windows.h>
#include <Shlwapi.h>

//gcc path_file_exists.c -o path_file_exists.exe -lshlwapi

int main() {

    // path to file that exists
    char filePath[] = "";

    char *lpStr;
    lpStr = filePath;

    int retval = PathFileExists(lpStr);
    if (retval == 1) {
        printf("\"%s\"\n exists\n", filePath);
    }
    else {
        printf("\"%s\"\n does not exist\n", filePath);
    }

    // path to file that doesnt exist
    char filePath2[] = "";
    char *lpStr2;
    lpStr2 = filePath2;

    retval = PathFileExists(lpStr2);
    if (retval == 1) {
        printf("\"%s\"\n exists\n", filePath2);
    }
    else {
        printf("\"%s\"\n does not exist\n", filePath2);
    }

    return 0;
}