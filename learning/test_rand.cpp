#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void) {
    int randNum;
    
    std::srand(std::time(0));

    randNum = std::rand() % 100;

    std::cout <<  ">>: " << randNum << std::endl;
}   
