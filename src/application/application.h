class Application {         // The class
  public:   
    int argc; 
    char **argv;            

    Application(int argc, char *argv[]) {
      this->argc = argc;
      this->argv = argv;
    }

    int run();
};
