#include "Form.hpp"

Form::Form() : _name("default"), 
    _gradeSigned(lowestGrade), _gradeExecute(lowestGrade),
    _isSigned(false) {
    std::cout << "Form: Default constructor called!" << std::endl;
}

Form::Form(const Form& other) : _name(other.getName()),
    _gradeSigned(lowestGrade), _gradeExecute(lowestGrade),
    _isSigned(other.isSigned()) {
    std::cout << "Form: Copy constructor called!" << std::endl;
    this->checkGrade(this->getGradeSigned());
    this->checkGrade(this->getGradeExecute());
}

Form::Form(const std::string& name,  const int gradeSigned, const int gradeExecute) :
    _name(name), _gradeSigned(gradeSigned), _gradeExecute(gradeExecute),
    _isSigned(false) {
        std::cout << "Form: Parameter constructor called!" << std::endl;
    this->checkGrade(gradeSigned);
    this->checkGrade(gradeExecute);
}

Form& Form::operator=(const Form& other) {
    this->checkGrade(other.getGradeSigned());
    this->checkGrade(other.getGradeExecute());
    if (this != &other)
        this->_isSigned = other.isSigned();
    return *this;
}

Form::~Form() {
    std::cout << "Form: Default destructor called!" << std::endl;
}

const char* Form::GradeTooLowException::what() const throw() {
    return 
        "GradeTooLowException: Grade is below the minimum allowed value.\n";
}

const char* Form::GradeTooHighException::what() const throw() {
    return
        "GradeTooHighException: Grade is above the maximum allowed value.\n";
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->getGradeSigned())
        throw GradeTooLowException();
    this->_isSigned = true;
}

const std::string& Form::getName() const {
    return this->_name;
}

const int& Form::getGradeSigned() const {
    return this->_gradeSigned;
}

const int& Form::getGradeExecute() const {
    return this->_gradeExecute;
}

const bool& Form::isSigned() const {
    return this->_isSigned;
}

void Form::checkGrade(const int& grade) const {
    if (grade < this->highestGrade)
        throw GradeTooHighException();
    if (grade > this->lowestGrade)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << f.getName() 
        << ", Form Grade Signed "
        << f.getGradeSigned() 
        << " and Form Grade Execute "  
        << f.getGradeExecute()
        << "." << std::endl;
    return out;
}
