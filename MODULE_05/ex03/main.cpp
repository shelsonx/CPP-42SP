#include <iomanip>
#include "AForm.hpp"
#include "Intern.hpp"

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

int main(void) {
	{
		std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
		std::cout << BLUE << "ShrubberyCreationForm Test: OK!" << std::endl << RESET;
		Intern intern;
		AForm* form;
		std::cout << GREEN;
		form = intern.makeForm("shrubbery creation", "sh1");
		std::cout << "target: " << form->getTarget() << std::endl << RESET;
		delete form;
	}

	{
		std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
		std::cout << BLUE << "RobotomyRequestForm Test: OK!" << std::endl << RESET;
		Intern intern;
		AForm* form;
		std::cout << GREEN;
		form = intern.makeForm("robotomy request", "ro");
		std::cout << "target: " << form->getTarget() << std::endl << RESET;
		delete form;
	}

	{
		std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
		std::cout << BLUE << "PresidentialPardonForm Test: OK!" << std::endl << RESET;
		Intern intern;
		AForm* form;
		std::cout << GREEN;
		form = intern.makeForm("presidential pardon", "pr");
		std::cout << "target: " << form->getTarget() << std::endl << RESET;
		delete form;
	}

	{
		std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl;
		std::cout << PURPLE << "Form Does not exists Test: FAIL!" << std::endl << RESET;
		try {
			Intern intern;
			AForm* form;
			form = intern.makeForm("any form", "pr");
			delete form;
		}
		catch (std::exception& e) {
			std::cout << RED;
			std::cout << e.what();
		}
	}
    std::cout << CYAN << std::setw(40) << std::setfill('*') << "" << std::endl << RESET;
}
