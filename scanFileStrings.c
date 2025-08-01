#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define MIN_STRING_LENGTH 4

const char *targets[] = {
    "CreateFileMappingA",
    "CreateProcessA",
    "CreateRemoteThread",
    "CreateRemoteThreadEx",
    "GetModuleHandleA",
    "GetProcAddress",
    "GetThreadContext",
    "HeapCreate",
    "LoadLibraryA",
    "LoadLibraryExA",
    "LocalAlloc",
    "MapViewOfFile",
    "MapViewOfFile2",
    "MapViewOfFile3",
    "MapViewOfFileEx",
    "OpenThread",
    "Process32First",
    "Process32Next",
    "QueueUserAPC",
    "ReadProcessMemory",
    "ResumeThread",
    "SetProcessDEPPolicy",
    "SetThreadContext",
    "SuspendThread",
    "Thread32First",
    "Thread32Next",
    "Toolhelp32ReadProcessMemory",
    "VirtualAlloc",
    "VirtualAllocEx",
    "VirtualProtect",
    "VirtualProtectEx",
    "WriteProcessMemory",
    "VirtualAllocExNuma",
    "VirtualAlloc2",
    "VirtualAlloc2FromApp",
    "VirtualAllocFromApp",
    "VirtualProtectFromApp",
    "CreateThread",
    "WaitForSingleObject",
    "OpenProcess",
    "OpenFileMappingA",
    "GetProcessHeap",
    "GetProcessHeaps",
    "HeapAlloc",
    "HeapReAlloc",
    "GlobalAlloc",
    "AdjustTokenPrivileges",
    "CreateProcessAsUserA",
    "OpenProcessToken",
    "CreateProcessWithTokenW",
    "NtAdjustPrivilegesToken",
    "NtAllocateVirtualMemory",
    "NtContinue",
    "NtCreateProcess",
    "NtCreateProcessEx",
    "NtCreateSection",
    "NtCreateThread",
    "NtCreateThreadEx",
    "NtCreateUserProcess",
    "NtDuplicateObject",
    "NtMapViewOfSection",
    "NtOpenProcess",
    "NtOpenThread",
    "NtProtectVirtualMemory",
    "NtQueueApcThread",
    "NtQueueApcThreadEx",
    "NtQueueApcThreadEx2",
    "NtReadVirtualMemory",
    "NtResumeThread",
    "NtUnmapViewOfSection",
    "NtWaitForMultipleObjects",
    "NtWaitForSingleObject",
    "NtWriteVirtualMemory",
    "RtlCreateHeap",
    "LdrLoadDll",
    "RtlMoveMemory",
    "RtlCopyMemory",
    "SetPropA",
    "WaitForSingleObjectEx",
    "WaitForMultipleObjects",
    "WaitForMultipleObjectsEx",
    "KeInsertQueueApc",
    "Wow64SetThreadContext",
    "NtSuspendProcess",
    "NtResumeProcess",
    "DuplicateToken",
    "NtReadVirtualMemoryEx",
    "CreateProcessInternal",
    "EnumSystemLocalesA",
    "UuidFromStringA",
    "DebugActiveProcessStop"
};

const size_t NUM_TARGETS = sizeof(targets) / sizeof(targets[0]);

int check_for_targets(const char *str) {
    for (size_t i = 0; i < NUM_TARGETS; ++i) {
        if (strstr(str, targets[i]) != NULL) {
            printf("> Match found: \"%s\" (target: \"%s\")\n", str, targets[i]);
            return 1;
        }
    }
    return 0;
}

int main() {

    char filepath[1024];

    printf("Enter file path: ");

    if (fgets(filepath, sizeof(filepath), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    size_t len = strlen(filepath);
    if (len > 0 && filepath[len - 1] == '\n') {
        filepath[len - 1] = '\0';
    }

    FILE * fp = fopen(filepath, "rb");
    if (!fp) {
        perror("Error couldnt open file");
        return 1;
    }

    char buffer[BUFSIZ];
    char stringBuffer[BUFSIZ];
    size_t strIndex = 0;

    int foundMatch = 0;

    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (isprint(c)) { //check if c is printable
            if (strIndex < sizeof(stringBuffer) - 1) {
                stringBuffer[strIndex++] = c;
            }
        } else {
            if (strIndex >= MIN_STRING_LENGTH) {
                stringBuffer[strIndex] = '\0';
                printf("%s\n", stringBuffer);

                // Check for the target strings
                if (check_for_targets(stringBuffer)) {
                    foundMatch = 1;
                }
            }
            strIndex = 0;
        }
    }

    // Final string after EOF
    if (strIndex >= MIN_STRING_LENGTH) {
        stringBuffer[strIndex] = '\0';
        printf("%s\n", stringBuffer);
        if (check_for_targets(stringBuffer)) {
            foundMatch = 1;
        }
    }

    if (!foundMatch) {
        printf("No matches for target strings were found.\n");
    }

    fclose(fp);

    return 0;
}