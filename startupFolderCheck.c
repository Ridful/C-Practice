#define _WIN32_WINNT 0x0500
#define _WIN32_IE 0x0500

#include <stdio.h>
#include <Windows.h>
#include <shlobj.h>
#include <Shlwapi.h>

//gcc startupFolderCheck.c -o startupFolderCheck.exe -lshell32 -lshlwapi

int main() {
    char path[MAX_PATH];

    if (SHGetFolderPathA(NULL, CSIDL_STARTUP, NULL, 0, path) == S_OK) {
        printf("Startup folder path: %s\n", path);
    } else {
        printf("Failed to get startup folder path.\n");
    }

    BOOL isEmpty = PathIsDirectoryEmptyA(path);
    printf("Is startup folder empty? %s\n", isEmpty ? "Yes" : "No");
    
    //todo - iterate through folder to get name of all files and directories in startup folder

    return 0;
}