#include "Bureaucrat.hpp"

int main(void) {
    try
    {
        Bureaucrat b1("b1", 0);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("b2", 151);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
