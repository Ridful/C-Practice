#include <windows.h>
#include <stdint.h>
#include <stdio.h>

// XOR decrypt
void xor_decrypt(char *data, size_t len, uint8_t key) {
    for (size_t i = 0; i < len; i++) {
        data[i] ^= key;
    }
}

// main
int main() {
    // XOR-encrypted "user32.dll" with key 0xAA
    char dll_enc[] = { 'u' ^ 0xAA, 's' ^ 0xAA, 'e' ^ 0xAA, 'r' ^ 0xAA,
                        '3' ^ 0xAA, '2' ^ 0xAA, '.' ^ 0xAA, 'd' ^ 0xAA,
                        'l' ^ 0xAA, 'l' ^ 0xAA, 0x00 }; // null terminator is plain
    xor_decrypt(dll_enc, 10, 0xAA); // decrypt "user32.dll"

    // XOR-encrypted "MessageBoxA" with key 0xAA
    char func_enc[] = { 'M' ^ 0xAA, 'e' ^ 0xAA, 's' ^ 0xAA, 's' ^ 0xAA,
                        'a' ^ 0xAA, 'g' ^ 0xAA, 'e' ^ 0xAA, 'B' ^ 0xAA,
                        'o' ^ 0xAA, 'x' ^ 0xAA, 'A' ^ 0xAA, 0x00 };
    xor_decrypt(func_enc, 11, 0xAA); // decrypt "MessageBoxA"

    // load dll
    HMODULE hUser32 = LoadLibraryA(dll_enc);
    if (!hUser32) {
        printf("Failed to load DLL\n");
        return 1;
    }

    // resolve the function
    FARPROC pMsgBox = GetProcAddress(hUser32, func_enc);
    if (!pMsgBox) {
        printf("Failed to resolve function\n");
        return 1;
    }

    // define the func pointer and call it
    typedef int (WINAPI *MSGBOX)(HWND, LPCSTR, LPCSTR, UINT);
    MSGBOX MessageBoxA_ = (MSGBOX)pMsgBox;

    MessageBoxA_(NULL, "Obfuscated call successful!", "Hello", MB_OK);

    return 0;
}
