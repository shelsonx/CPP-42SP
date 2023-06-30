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

        Form f10("f10", 44, 7);
        std::cout << f10 << std::endl;
        std::cout << PURPLE << "is it Signed? " 
            << (f10.isSigned() ? "Yes" : "Not") << std::endl << RESET;
        
        Bureaucrat b10("b10", 45);
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
