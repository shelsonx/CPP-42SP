#include <iostream>

int main(void)
{
    std::string str("HI THIS IS BRAIN");
    std::string* strPTR = &str;
    std::string& strREF = str;

    std::cout << "address of the str: " << &str << std::endl;
    std::cout << "address of the strPTR: " << strPTR << std::endl;
    std::cout << "address of the strREF: " << &strREF << std::endl;

    std::cout << "value of the str: " << str << std::endl;
    std::cout << "value of the strPTR: " << *strPTR << std::endl;
    std::cout << "value of the strREF: " << strREF << std::endl;
}
