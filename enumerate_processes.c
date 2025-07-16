#include <windows.h>
#include <TlHelp32.h>
#include <tchar.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    HANDLE hProcessSnap;
    HANDLE hProcess;
    PROCESSENTRY32 pe32;
    DWORD dwPriorityClass;

    // Take a snapshot of all processes in the system
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        _tprintf(TEXT("CreateToolhelp32Snapshot failed: %lu\n"), GetLastError());
        return 1;
    }

    pe32.dwSize = sizeof(PROCESSENTRY32);

    // get info about the first process, exit if unsuccessful
    if (!Process32First(hProcessSnap, &pe32)) {
        _tprintf(TEXT("Process32First failed: %lu\n"), GetLastError());
        CloseHandle(hProcessSnap);
        return 1;
    }

    // walk through the snapshot of processes and display sone info on each process
    do {
        _tprintf(TEXT("\nPROCESS NAME: = %s"), pe32.szExeFile);
        _tprintf(TEXT("\nProcess ID: = 0x%08X"), pe32.th32ProcessID);
        _tprintf(TEXT("\nThread COUNT: = %d"), pe32.cntThreads);
        _tprintf(TEXT("\nPARENT PROCESS ID: = 0x%08X"), pe32.th32ParentProcessID);
        _tprintf(TEXT("\nPRIORITY BASE: = %d"), pe32.pcPriClassBase);
        _tprintf(TEXT("\n-------------------------------"));

    } while (Process32Next(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);
    return 0;
}
