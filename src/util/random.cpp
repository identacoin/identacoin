#include <cstdlib>
#include <iostream>
#include <ctime>
#include "random.h" 

RandNum::RandNum(int max) 
{
    this->max = max;
    std::srand(std::time(nullptr)); // use current time as seed for random generator
}

int RandNum::generate() {
    
    return 1 + std::rand()/((RAND_MAX + 1u)/this->max);  

}