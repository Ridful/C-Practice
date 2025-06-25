#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <tchar.h>
#include <lmcons.h> //for UNLEN
//#include <winnls.h> //for GetUserDefaultGeoName & GetSystemDefaultGeoName
#include <locale.h>

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

    //Get information about the processor
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    printf("Number of processors: %u\n", sysInfo.dwNumberOfProcessors);
    printf("Page Size: %u bytes\n", sysInfo.dwPageSize);
    printf("Processor Type: %u\n", sysInfo.dwProcessorType);

    printf("Processor Architecture: ");
    switch (sysInfo.wProcessorArchitecture) {

        case PROCESSOR_ARCHITECTURE_AMD64:
            printf("x64 (AMD or Intel)\n");
            break;

        case PROCESSOR_ARCHITECTURE_ARM:
            printf("ARM\n");
            break;

        case PROCESSOR_ARCHITECTURE_INTEL:
            printf("x86\n");
            break;

        default:
            printf("Unknown Architecture");
            break;
    }

    // Get local time
    SYSTEMTIME st;
    GetLocalTime(&st);

    printf("Local time: %02d-%02d-%04d %02d:%02d:%02d\n",
        st.wDay, st.wMonth, st.wYear,
        st.wHour, st.wMinute, st.wSecond);

    // Get time zone info
    TIME_ZONE_INFORMATION tzi;
    DWORD result = GetTimeZoneInformation(&tzi);

    // Print time zone name
    if (result == TIME_ZONE_ID_STANDARD || result == TIME_ZONE_ID_UNKNOWN) {
        wprintf(L"Time zone (Standard): %s\n", tzi.StandardName);
    } else if (result == TIME_ZONE_ID_DAYLIGHT) {
        wprintf(L"Time zone (Daylight): %s\n", tzi.DaylightName);
    } else {
        printf("Failed to get time zone info.\n");
    }

    // Print bias (difference from UTC in minutes)
    printf("UTC offset: %d minutes\n", -tzi.Bias); // Negative because Bias is added to local time
}