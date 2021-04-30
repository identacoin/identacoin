// Instacoin Node
// main.cpp
// 

#include "application/application.h"
#include "test/testmode.h"

#ifdef __WIN32__
#include <Windows.h>
#include <excpt.h>
#endif
#include <exception>

int main(int argc, char *argv[]) {

    Application* a = new Application(argc, argv);

    a->start();

    a->join();

    return 0;
   
}