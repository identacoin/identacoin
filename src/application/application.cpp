#include "application.h"

#include <iostream>
#include <string>

#include "../networking/serversocket.h"
#include "../networking/clientsocket.h"
#include "../test/testmode.h"

std::string serverMode ("Server");
std::string clientMode ("Client");
std::string testMode ("Test");

void Application::run() {

     /*
    

    */
    std::cout << "Instacoin alpha v" << VERSION << " Built: " << BUILDDATE << "\n";
    if (argc > 1) {

        std::string str1 (argv[1]);

        std::cout << "Arg " << str1 << "\n";

        if (str1.compare(serverMode) == 0) {
            std::cout << serverMode << " Mode\n";

            ServerSocket* sock = new ServerSocket();

            sock->start();    

            sock->join();

        } else if (str1.compare(clientMode) == 0) {
            std::cout << clientMode << " Mode\n";

            ClientSocket* client = new ClientSocket();

            client->connectSocket();

        } else if (str1.compare(testMode) == 0) {

            std::cout << testMode << " Mode\n";

            Test* test = new Test();

            test->runTest();


        } else {
            std::cout << "unsupported Mode\n";
        }

    }

    return;

}