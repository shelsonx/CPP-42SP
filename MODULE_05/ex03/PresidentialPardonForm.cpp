#include "PresidentialPardonForm.hpp"

const int GradesPresidential::SIGN = 25;
const int GradesPresidential::EXECUTE = 5;

PresidentialPardonForm::PresidentialPardonForm() : 
    AForm("PresidentialPardonForm", GradesPresidential::SIGN, GradesPresidential::EXECUTE) {
    std::cout << "PresidentialPardonForm: Default constructor called!" << std::endl;
    this->setTarget("Default");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    :AForm("PresidentialPardonForm", GradesPresidential::SIGN, GradesPresidential::EXECUTE) {
    std::cout << "PresidentialPardonForm: Copy constructor called!" << std::endl;
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
        std::cout << "PresidentialPardonForm: Copy assignment constructor called!" << std::endl;
   (void) other;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("PresidentialPardonForm", GradesPresidential::SIGN, GradesPresidential::EXECUTE) {
        std::cout << "PresidentialPardonForm: Parameter constructor called!" << std::endl;
        this->setTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm: Default destructor called!" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
