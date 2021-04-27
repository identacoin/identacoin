

#include "w32socks.h"

#ifdef __WIN32__
#include <winsock2.h>
#include <ws2tcpip.h>
#endif

#include <stdlib.h>

#include <string.h>
#include <iostream>

#include <stdio.h>
#include <unistd.h>

int W32Socks::startUp() {
    
    #ifdef __WIN32__

    WSADATA wsaData;
    WORD wVersionRequested = MAKEWORD(2, 2);

    int err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        /* Tell the user that we could not find a usable */
        /* Winsock DLL.                                  */
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }
    #endif
    
    return 0;
}