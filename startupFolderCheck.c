#define _WIN32_WINNT 0x0500
#define _WIN32_IE 0x0500

#include <stdio.h>
#include <Windows.h>
#include <shlobj.h>
#include <Shlwapi.h>

//gcc startupFolderCheck.c -o startupFolderCheck.exe -lshell32 -lshlwapi

// Prints the full path for a common location
void printFolderPath(int csidl, const char* name) {
    char path[MAX_PATH];
    if (SHGetFolderPathA(NULL, csidl, NULL, 0, path) == S_OK) {
        printf("%s: %s\n", name, path);
    } else {
        printf("Failed to get %s path.\n", name);
    }
}

// Prints the files and directories inside of a directory
void printFilesDirsInPath(char* startupPath) {

    strcat(startupPath, "\\*");
    printf("%s\n", startupPath);

    WIN32_FIND_DATA findFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;

    hFind = FindFirstFile(startupPath, &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("findFirstFile failed.\n");
    }
    do {
        if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0) {
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                printf("Directory: %s\n", findFileData.cFileName);
            } else {
                printf("File: %s\n", findFileData.cFileName);
            }
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    DWORD dwError = GetLastError();
    if (dwError != ERROR_NO_MORE_FILES) {
        printf("FindNextFile failed (%lu)\n", dwError);
    }

    FindClose(hFind);
}

int main() {

    // Print the paths for some common locations
    printFolderPath(CSIDL_APPDATA, "AppData (Roaming)");
    printFolderPath(CSIDL_COMMON_APPDATA, "ProgramData");
    printFolderPath(CSIDL_PERSONAL, "Documents");
    printFolderPath(CSIDL_DESKTOPDIRECTORY, "Desktop");

    char startupPath[MAX_PATH];

    // Get the Startup folder location
    if (SHGetFolderPathA(NULL, CSIDL_STARTUP, NULL, 0, startupPath) == S_OK) {
        printf("Startup folder path: %s\n", startupPath);

        BOOL isEmpty = PathIsDirectoryEmptyA(startupPath);
        printf("Is startup folder empty? %s\n", isEmpty ? "Yes" : "No");

        // If the startup folder isnt empty, print all files & dirs in startup folder
        if (!isEmpty) {
            printFilesDirsInPath(startupPath);
        }
    }
    
    else {
        printf("Failed to get startup folder path.\n");
    }

    return 0;
}