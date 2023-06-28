#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(lowestGrade) {
    std::cout << "Bureaucrat: Default constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
    _name(other.getName()) {
    std::cout << "Bureaucrat: Copy constructor called!" << std::endl;
    this->checkGrade(other.getGrade());
    this->_grade = other.getGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat: Copy assignment constructor called!" << std::endl;
    this->checkGrade(other.getGrade());
    if (this != &other)
        this->_grade = other.getGrade();
    return *this;
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) :
    _name(name) {
    std::cout << "Bureaucrat: Parameter constructor called!" << std::endl;
    this->checkGrade(grade);
    this->_grade = grade;
}

void Bureaucrat::increment() {
    this->_grade--;
    this->checkGrade(this->getGrade());
}

void Bureaucrat::decrement() {
    this->_grade++;
    this->checkGrade(this->getGrade());
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat: Default destructor called!" << std::endl;
}

const std::string& Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return
        "GradeTooLowException: Grade is below the minimum allowed value.\n"; 
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return 
        "GradeTooHighException: Grade is above the maximum allowed value.\n"; 
}

void Bureaucrat::checkGrade(const int grade) const {
    if (grade < this->highestGrade)
        throw GradeTooHighException();
    if (grade > this->lowestGrade)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " 
        << b.getGrade() << "." << std::endl;
    return out;
}
