#include <iostream>

int main()
{
    int numberOfBalls = 42;

    int* ballsPtr = &numberOfBalls;
    int& ballsRef = numberOfBalls;
    // The reference will be pointing to the variable
    //from this point on, you can't change what your reference is pointer to
    std::cout << numberOfBalls << " " << *ballsPtr << " " << ballsRef << std::endl;
    *ballsPtr = 21;
    std::cout << numberOfBalls << std::endl;
    ballsRef = 84;
    std::cout << numberOfBalls << std::endl;
    return (0);
}
