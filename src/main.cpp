// Instacoin Node
// main.cpp
// 

#include "application/application.h"

int main(int argc, char *argv[]) {

    Application* a = new Application(argc, argv);
    
    a->start();

    a->join();

    return 0;
   
}