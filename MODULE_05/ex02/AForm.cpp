#include "AForm.hpp"

AForm::AForm() : _name("default"), 
    _gradeSigned(lowestGrade), _gradeExecute(lowestGrade),
    _isSigned(false) {
    std::cout << "AForm: Default constructor called!" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other.getName()),
    _gradeSigned(lowestGrade), _gradeExecute(lowestGrade),
    _isSigned(other.isSigned()) {
    std::cout << "AForm: Copy constructor called!" << std::endl;
    this->checkGrade(this->getGradeSigned());
    this->checkGrade(this->getGradeExecute());
}

AForm::AForm(const std::string& name,  const int gradeSigned, const int gradeExecute) :
    _name(name), _gradeSigned(gradeSigned), _gradeExecute(gradeExecute),
    _isSigned(false) {
        std::cout << "AForm: Parameter constructor called!" << std::endl;
    this->checkGrade(gradeSigned);
    this->checkGrade(gradeExecute);
}

AForm& AForm::operator=(const AForm& other) {
    this->checkGrade(other.getGradeSigned());
    this->checkGrade(other.getGradeExecute());
    if (this != &other)
        this->_isSigned = other.isSigned();
    std::cout << "AForm: Copy assignment constructor called!" << std::endl;
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm: Default destructor called!" << std::endl;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return 
        "GradeTooLowException: Grade is below the minimum allowed value.\n";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return
        "GradeTooHighException: Grade is above the maximum allowed value.\n";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return
        "A form has not been signed yet.\n";
}

void AForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();
    if (this->isSigned() == false)
        throw AForm::FormNotSignedException();
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->getGradeSigned())
        throw GradeTooLowException();
    this->_isSigned = true;
}

const std::string& AForm::getName() const {
    return this->_name;
}

const int& AForm::getGradeSigned() const {
    return this->_gradeSigned;
}

const int& AForm::getGradeExecute() const {
    return this->_gradeExecute;
}

const bool& AForm::isSigned() const {
    return this->_isSigned;
}

const std::string& AForm::getTarget() const {
    return this->_target;
}

void AForm::setTarget(const std::string& target) {
    this->_target = target;
}

void AForm::checkGrade(const int& grade) const {
    if (grade < this->highestGrade)
        throw GradeTooHighException();
    if (grade > this->lowestGrade)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << f.getName() 
        << ", AForm Grade Signed "
        << f.getGradeSigned() 
        << " and AForm Grade Execute "  
        << f.getGradeExecute()
        << "." << std::endl;
    return out;
}
