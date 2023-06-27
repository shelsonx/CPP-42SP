#include <iomanip>
#include "Bureaucrat.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

int main(void) {
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << PURPLE << "Init with value 0 Test: FAIL!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start b1:" << std::endl << GREEN;
        Bureaucrat b1("b1", 0);
    }
    catch (std::exception & e)
    {
        std::cout << RED;
        std::cout << e.what();
        std::cout << YELLOW << "end b1." << std::endl << RESET;
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << PURPLE << "Init with value 151 Test: FAIL!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start b2:" << std::endl << GREEN;
        Bureaucrat b2("b2", 151);
    }
    catch (std::exception & e)
    {
        std::cout << RED;
        std::cout << e.what();
        std::cout << YELLOW << "end b2." << std::endl << RESET;
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Init with value 150 Test: OK!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start b3:" << std::endl << GREEN;
        Bureaucrat b3("b3", 150);
        std::cout << b3;
        std::cout << YELLOW << "end b3." << std::endl << RESET;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Use default constructor: OK!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start b4:" << std::endl << GREEN;
        Bureaucrat b4;
        std::cout << b4 << std::endl;
        std::cout << YELLOW << "end b4." << std::endl << RESET;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Use Copy Assignment constructor: OK!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start b5 and b6:" << std::endl << GREEN;
        Bureaucrat b5("b5", 5);
        Bureaucrat b6("b6", 6);
        b6 = b5;
        std::cout << b5 << std::endl;
        std::cout << b6 << std::endl;
        std::cout << YELLOW << "end b5 and b6." << std::endl << RESET;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Use Copy constructor: OK!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start b7 and b8:" << std::endl << GREEN;
        Bureaucrat b7("b7", 7);
        Bureaucrat b8(b7);
        std::cout << b7 << std::endl;
        std::cout << b8 << std::endl;
        std::cout << YELLOW << "end b7 and b8." << std::endl << RESET;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Increment and Decrement function Test: OK!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start b9:" << std::endl << GREEN;
        Bureaucrat b9("b9", 3);
        std::cout << b9 << std::endl;
        b9.increment();
        std::cout << b9 << std::endl;

        b9.decrement();
        b9.decrement();
        std::cout << b9 << std::endl;
        std::cout << YELLOW << "end b9." << std::endl << RESET;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << PURPLE << "Increment function Test: FAIL!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start b10:" << std::endl << GREEN;

        Bureaucrat b10("10", 1);
        std::cout << b10 << std::endl << RED;
        b10.increment();
        std::cout << b10 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
        std::cout << YELLOW << "end b10." << std::endl << RESET;
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << PURPLE << "Decrement function Test: FAIL!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start b11:" << std::endl << GREEN;

        Bureaucrat b11("10", 150);
        std::cout << b11 << std::endl << RED;
        b11.decrement();
        std::cout << b11 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
        std::cout << YELLOW << "end b11." << std::endl << RESET;
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl << RESET;
}
