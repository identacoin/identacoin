#include "threadbase.h"

ThreadBase::ThreadBase() {
    
}

void ThreadBase::join() {
    if (t.joinable()) {
        t.join();
    }
}

void ThreadBase::detach() {
    t.detach();
}

void ThreadBase::run() {
    std::cout << "hi\n";
}

void runThread(ThreadBase* me) {
    me->run();
    me->detach();
    delete me;
}

void ThreadBase::start() {
    t = std::thread(runThread, this);
}