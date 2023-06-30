#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern: Default constructor called!" << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Intern: Copy constructor called!" << std::endl;
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern: Copy assignment constructor called!" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern: Default destructor called!" << std::endl;
}

AForm* Intern::shrubberyCreationForm(const std::string target) const {
    return new ShrubberyCreationForm(target);
}
AForm* Intern::robotomyRequestForm(const std::string target) const {
    return new RobotomyRequestForm(target);
}
AForm* Intern::presidentialPardonForm(const std::string target) const {
    return new PresidentialPardonForm(target);
}

const char* Intern::FormDoesNotExists::what() const throw() {
    return
        "Form does not exists.\n";
}

int Intern::getIndexForm(const std::string name) const {
    std::string typesForms[this->SIZE] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    for (int i = 0; i < this->SIZE; i++)
    {
        if (name.compare(typesForms[i]) == 0)
            return i;
    }
    return  -1;
}

AForm* Intern::makeForm(const std::string name, const std::string target) {
    AForm* form;
    int index;
    
    AForm* (Intern::*forms[this->SIZE])(const std::string) const = {
        &Intern::shrubberyCreationForm, 
        &Intern::robotomyRequestForm, 
        &Intern::presidentialPardonForm};
    index =  this->getIndexForm(name);
    if (index != -1) {
        form = (this->*forms[index])(target);
        std::cout << "Intern creates " << form->getName() << std::endl;
        return form;
    }
    throw Intern::FormDoesNotExists();
}
