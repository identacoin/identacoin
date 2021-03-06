#include <unistd.h>
#include <stdio.h>

#ifdef __WIN32__
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#endif


#include <stdlib.h>

#include <string.h>
#include <iostream>

#include "../threads/threadbase.h"

class ServerSocket : public ThreadBase {         // The class

  private:
    int server_fd;
    struct sockaddr_in address;

    void createSocket();
    void setOptions();
    void bindSocket();
    void listenSocket();
    
  public:               // Access specifier
    int openStocket(void);
    virtual void run();
};
