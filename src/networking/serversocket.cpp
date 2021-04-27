#define PORT 8080

#include "serversocket.h"
#include "../win32/w32socks.h"
#include "serverconnection.h"

void ServerSocket::run() {
    this->openStocket();
}

void ServerSocket::createSocket() {
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
}

void ServerSocket::setOptions() {

    BOOL bOptVal = TRUE;
    int bOptLen = sizeof (BOOL);

    // Forcefully attaching socket to the port 8080
    int result = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
                                                  (char *) &bOptVal, bOptLen);
                                                  
    if (result)    {
        std::cout << result << "\n"; 
        wprintf(L"setsockopt for SO_KEEPALIVE failed with error: %u\n", WSAGetLastError());
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
}

void ServerSocket::bindSocket() {
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

void ServerSocket::listenSocket() {
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}
    

int ServerSocket::openStocket(void)
{
    int new_socket, valread;
      
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *hello = "Hello from server";

    W32Socks w32;
    w32.startUp();
       
    this->createSocket();
       
    this->setOptions();

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
       
    this->bindSocket();

    this->listenSocket();
    
    do {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                        (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        ServerConnection* conn = new ServerConnection(new_socket);

        conn->start();
    
    } while(true);
    
    return 0;
}