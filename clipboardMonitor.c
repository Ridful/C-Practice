#include <Windows.h>
#include <wchar.h>
#include <stdio.h>


// gcc clipboardMonitor.c -o clipboardMonitor.exe -municode -luser32

int main() {
    wchar_t lastText[4096] = L"";

    while (1) {
        if(OpenClipboard(NULL)) {

            HANDLE hData = GetClipboardData(CF_UNICODETEXT);

            if(hData) {
                wchar_t* pszText = (wchar_t*)GlobalLock(hData);
                // 
                if (pszText && wcscmp(pszText, lastText) != 0) {
                    wprintf(L"Clipboard: %s\n", pszText);
                    wcscpy(lastText, pszText);
                }
                if (pszText) GlobalUnlock(hData);
            }
            CloseClipboard();
        }

        Sleep(500);
    }

    return 0;
}