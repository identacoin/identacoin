#include "../threads/threadbase.h"

class Application : public ThreadBase {         // The class
  private:   
    int argc; 
    char **argv;            

  public:
    Application(int argc, char **argv) : ThreadBase() {
      this->argc = argc;
      this->argv = argv;
    }

    virtual void run();
};
