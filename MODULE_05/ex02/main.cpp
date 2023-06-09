#include <iomanip>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
    std::cout << BLUE << "Form signed Successfully Test: OK!" << std::endl << RESET;
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

    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Bureaucrat execute form Test: OK!" << std::endl << RESET;
    ShrubberyCreationForm s4("luccaForm");
    Bureaucrat b3("b3", 44);
    try {
        std::cout << GREEN;
        b3.signForm(s4);
        b3.executeForm(s4);
        std::cout << RESET;
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }

    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "RobotomyRequestForm execute method Test: OK!" << std::endl << RESET;
    try {
        Bureaucrat b4("b4", 44);
        RobotomyRequestForm r1("r1");
        b4.signForm(r1);
        r1.execute(b4);
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }

    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "PresidentialPardonForm execute method Test: OK!" << std::endl << RESET;
    try {
        Bureaucrat b5("b5", 4);
        PresidentialPardonForm p1("p1-Presidential");
        b5.signForm(p1);
        std::cout << GREEN;
        p1.execute(b5);
        std::cout << RESET;
    }
    catch (std::exception& e) {
        std::cout << e.what();
    }
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl << RESET;
}
