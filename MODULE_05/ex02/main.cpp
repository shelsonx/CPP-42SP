#include <iomanip>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

int main(void) {
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << PURPLE << "Form not signed Test: FAIL!" << std::endl << RESET;
    ShrubberyCreationForm s1("home");
    try {
        std::cout << BLUE << "is it Signed? " 
            << RED << (s1.isSigned() ? "Yes" : "Not") << std::endl
            << RESET;
        s1.execute(Bureaucrat("b1", 136));
    }
    catch (std::exception& e) {
        std::cout << RED;
        std::cout << e.what();
    }

    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Form signed Successfully Test: FAIL!" << std::endl << RESET;
    ShrubberyCreationForm s2("shellForm");
    Bureaucrat b1("b1", 44);
    try {
        b1.signForm(s2);
        std::cout << BLUE << "is it Signed? " 
            << GREEN << (s2.isSigned() ? "Yes" : "Not") << std::endl
            << RESET;
        s2.execute(b1);
    }
    catch (std::exception& e) {
        std::cout << RED;
        std::cout << e.what();
    }

    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << PURPLE << "Form invalid grade Test: FAIL!" << std::endl << RESET;
    ShrubberyCreationForm s3("luccaForm");
    Bureaucrat b2("b2", 138);
    try {
        b2.signForm(s3);
        std::cout << BLUE << "is it Signed? " 
            << RED << (s3.isSigned() ? "Yes" : "Not") << std::endl
            << RESET;
        s3.execute(b2);
    }
    catch (std::exception& e) {
        std::cout << RED;
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl << RESET;
}
