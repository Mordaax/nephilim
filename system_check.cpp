#include <windows.h>
#include <tlhelp32.h>
#include <strsafe.h>
#include <iostream>
void syscheck() {
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    DWORD numberOfProcessors = systemInfo.dwNumberOfProcessors;

    MEMORYSTATUSEX memoryStatus;
    memoryStatus.dwLength = sizeof(memoryStatus);
    GlobalMemoryStatusEx(&memoryStatus);
    DWORD RAMMB = memoryStatus.ullTotalPhys / 1024 / 1024;
    if (numberOfProcessors < 1) exit(0);
    if (RAMMB < 1048) exit(0);

    // Process chekcing
    const wchar_t* exeNames[] = { L"WIRESHARK.EXE", L"PROCMON.EXE", L"OLLYDBG.EXE", L"PROCESSHACKER.EXE", L"PROCDOT.EXE", L"REGSHOT-X86-ANSI.EXE",L"SMSNIFF.EXE" };
    PROCESSENTRY32W processEntry = { 0 };
    processEntry.dwSize = sizeof(PROCESSENTRY32W);
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    WCHAR processName[MAX_PATH + 1];
    if (Process32FirstW(hSnapshot, &processEntry))
    {
        do
        {
            StringCchCopyW(processName, MAX_PATH, processEntry.szExeFile);
            CharUpperW(processName);
            for (int i = 0; i < sizeof(exeNames) / sizeof(exeNames[0]); i++) {
                if (wcscmp(processName, exeNames[i]) == 0) {
                    
                    exit(0);
                }
            }

        } while (Process32NextW(hSnapshot, &processEntry));
    }
}