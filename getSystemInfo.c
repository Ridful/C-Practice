#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <tchar.h>
#include <lmcons.h> //for UNLEN

int main() {

    // Get ComputerName
    TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName) / sizeof(computerName[0]);

    if (GetComputerName(computerName, &size)) {
        printf("ComputerName: %s\n", computerName);
    }


    // Get Username
    TCHAR userName[UNLEN + 1];
    DWORD userSize = sizeof(userName) / sizeof(userName[0]);

    if (GetUserName(userName, &userSize)) {
        printf("UserName: %s\n", userName);
    }
}