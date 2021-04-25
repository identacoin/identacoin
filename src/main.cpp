// Your First C++ Program

#include <iostream>
#include <string>

#include "networking/serversocket.h"
#include "networking/clientsocket.h"

std::string serverMode ("Server");
std::string clientMode ("Client");

int main(int argc, char *argv[]) {

    /*
    

    */
    std::cout << "Instacoin alpha v0.0. " << argc << "\n";
    if (argc > 1) {

        std::string str1 (argv[1]);

        std::cout << "Arg " << str1 << "\n";

        if (str1.compare(serverMode) == 0) {
            std::cout << serverMode << " Mode\n";

            ServerSocket* sock = new ServerSocket();

            sock->openStocket();    

        } else if (str1.compare(clientMode) == 0) {
            std::cout << clientMode << " Mode\n";

            ClientSocket* client = new ClientSocket();

            client->connectSocket();

        } else {
            std::cout << "unsupported Mode\n";
        }

    }
    return 0;
}