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

class ServerConnection : public ThreadBase {         // The class

  private:
    int new_socket;
    
  public:               // Access specifier
    ServerConnection(int fd);
    int handleRequest(void);
    virtual void run();
};
