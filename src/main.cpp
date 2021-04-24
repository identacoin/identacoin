// Your First C++ Program

#include <iostream>

#include "networking/serversocket.h"

int main() {

    ServerSocket* sock = new ServerSocket();

    sock->openStocket();

    std::cout << "Hello World!";
    return 0;
}