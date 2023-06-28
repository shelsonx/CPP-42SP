#include <iomanip>
#include "Form.hpp"

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
        std::cout << YELLOW << "start f1:" << std::endl << GREEN;
        Form f1("f1", 0, 0);
    }
    catch (std::exception & e)
    {
        std::cout << RED;
        std::cout << e.what();
        std::cout << YELLOW << "end f1." << std::endl << RESET;
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << PURPLE << "Init with value 151 Test: FAIL!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start f2:" << std::endl << GREEN;
        Form f2("f2", 151, 151);
    }
    catch (std::exception & e)
    {
        std::cout << RED;
        std::cout << e.what();
        std::cout << YELLOW << "end f2." << std::endl << RESET;
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Init with value 150 Test: OK!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start f3:" << std::endl << GREEN;
        Form f3("f3", 150, 150);
        std::cout << f3;
        std::cout << YELLOW << "end f3." << std::endl << RESET;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Use default constructor: OK!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start f4:" << std::endl << GREEN;
        Bureaucrat f4;
        std::cout << f4 << std::endl;
        std::cout << YELLOW << "end f4." << std::endl << RESET;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Use Copy Assignment constructor: OK!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start f5 and f6:" << std::endl << GREEN;
        Form f5("f5", 5, 10);
        Form f6("f6", 6, 11);
        f6 = f5;
        std::cout << f5 << std::endl;
        std::cout << f6 << std::endl;
        std::cout << YELLOW << "end f5 and f6." << std::endl << RESET;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Use Copy constructor: OK!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start f7 and f8:" << std::endl << GREEN;
        Form f7("f7", 7, 15);
        Form f8(f7);
        std::cout << f7 << std::endl;
        std::cout << f8 << std::endl;
        std::cout << YELLOW << "end f7 and f8." << std::endl << RESET;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Signed function Test: OK!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start f9:" << std::endl << GREEN;

        Form f9("f9", 3, 3);
        std::cout << f9 << std::endl;
        std::cout << PURPLE << "is it Signed? " 
            << (f9.isSigned() ? "Yes" : "Not") << std::endl << RESET;
        
        Bureaucrat b9("b9", 3);
        std::cout << GREEN << b9 << std::endl << RESET;
        f9.beSigned(b9);
        std::cout << GREEN << "is it Signed? " 
            << (f9.isSigned() ? "Yes" : "Not") << std::endl << RESET;
        
        std::cout << YELLOW << "end f9." << std::endl << RESET;
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << PURPLE << "Signed function Test: FAIL!" << std::endl << RESET;
    try
    {
        std::cout << YELLOW << "start f10:" << std::endl << GREEN;

        Form f10("f10", 42, 7);
        std::cout << f10 << std::endl;
        std::cout << PURPLE << "is it Signed? " 
            << (f10.isSigned() ? "Yes" : "Not") << std::endl << RESET;
        
        Bureaucrat b10("b10", 0);
        std::cout << GREEN << b10 << std::endl << RESET;
        f10.beSigned(b10);
        std::cout << "is it Signed? " 
            << (f10.isSigned() ? "Yes" : "Not") << std::endl << RESET;
    }
    catch (std::exception & e)
    {
        std::cout << RED;
        std::cout << e.what();
        std::cout << YELLOW << "end f10." << std::endl << RESET;
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "signForm in  Bureaucrat: OK!" << std::endl << GREEN;
   
    Bureaucrat b11("b11", 7);
    b11.signForm(Form("f11", 42, 42));

    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << PURPLE << "signForm in  Bureaucrat: FAIL!" << std::endl << RED;
    
    Bureaucrat b12("b12", 7);
    b12.signForm(Form("f12", 1, 1));
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl << RESET;
}
