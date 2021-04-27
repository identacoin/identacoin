#include "threadbase.h"

ThreadBase::ThreadBase() {
    
}

void ThreadBase::join() {
    t.join();
}

void ThreadBase::run() {
    std::cout << "hi\n";
}

void runThread(ThreadBase* me) {
    me->run();

}

void ThreadBase::start() {
    t = std::thread(runThread, this);
}