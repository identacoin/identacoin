#include <iostream>
#include <thread>

class ThreadBase {         // The class

    private:
        std::thread t;        

    public:       
          // Access specifier
        ThreadBase();
        void start(); 
        virtual void run();        
        void join();

};
