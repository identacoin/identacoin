#define PORT 8080

#include "serverconnection.h"

ServerConnection::ServerConnection(int fd) : ThreadBase() {
    this->new_socket = fd;
}

void ServerConnection::run() {
    this->handleRequest();
}

int ServerConnection::handleRequest(void)
{
    int valread;
          
    char buffer[1024] = {0};
    const char *hello = "Hello from server";

    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    return 0;
}