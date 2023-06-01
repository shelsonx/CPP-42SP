#include "ReplaceStr.hpp"

int main()
{
    std::string str = "Hello, world! Hello, universe!";
    std::string s1 = "Hello";
    std::string s2 = "Hi";

    ReplaceStr().replace(str, s1, s2);
    std::cout << str << std::endl;
}
