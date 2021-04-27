#include <iostream>
#include <thread>

#ifndef __IC_THREAD_BASE
#define __IC_THREAD_BASE

class ThreadBase {         // The class

    private:
        std::thread t;        

    public:       
          // Access specifier
        ThreadBase();
        void start(); 
        virtual void run();        
        void join();
        void detach();

};

#endif