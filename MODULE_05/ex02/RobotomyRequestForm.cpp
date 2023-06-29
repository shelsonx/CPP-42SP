#include "RobotomyRequestForm.hpp"

const int GradesRobot::SIGN = 72;
const int GradesRobot::EXECUTE = 45;

RobotomyRequestForm::RobotomyRequestForm() : 
    AForm("RobotomyRequestForm", GradesRobot::SIGN, GradesRobot::EXECUTE) {
    std::cout << "RobotomyRequestForm: Default constructor called!" << std::endl;
    this->setTarget("Default");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    :AForm("RobotomyRequestForm", GradesRobot::SIGN, GradesRobot::EXECUTE) {
    std::cout << "RobotomyRequestForm: Copy constructor called!" << std::endl;
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
        std::cout << "RobotomyRequestForm: Copy assignment constructor called!" << std::endl;
   (void) other;
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("RobotomyRequestForm", GradesRobot::SIGN, GradesRobot::EXECUTE) {
        std::cout << "RobotomyRequestForm: Parameter constructor called!" << std::endl;
        this->setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm: Default destructor called!" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);

    int randNum;

    std::cout << "ZzZzZzZzZzZzZzZzZzZzZzZzZzZzZzZzZ..." << std::endl;
    std::cout << "Bleepity bloopity bzzzzzzzzzzzzzzzzzzzz..." << std::endl;
    std::cout << "Whirrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr..." << std::endl;
    
    std::srand(std::time(0));
    randNum = std::rand() % 100;
    if (randNum <= 50) {
        std::cout << "\e[32m Robotization completed successfully. [" 
        << randNum << "]" << std::endl;
    }
    else {
        std::cout << "\e[31m Failed to robotize. [" 
        << randNum << "]" << std::endl;
    }
}
