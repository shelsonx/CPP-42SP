#include "ShrubberyCreationForm.hpp"
#include <fstream>

const int Grades::SIGN = 145;
const int Grades::EXECUTE = 137;

const std::string Grades::ASCII_TREE =
    "               ,@@@@@@@,\n"
    "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
    "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
    "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
    "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
    "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
    "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
    "       |o|        | |         | |\n"
    "       |.|        | |         | |\n"
    "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";


ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm("ShrubberyCreationForm", Grades::SIGN, Grades::EXECUTE) {
    std::cout << "ShrubberyCreationForm: Default constructor called!" << std::endl;
    this->setTarget("Default");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    :AForm("ShrubberyCreationForm", Grades::SIGN, Grades::EXECUTE) {
    std::cout << "ShrubberyCreationForm: Copy constructor called!" << std::endl;
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
        std::cout << "ShrubberyCreationForm: Copy assignment constructor called!" << std::endl;
   (void) other;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", Grades::SIGN, Grades::EXECUTE) {
        std::cout << "ShrubberyCreationForm: Parameter constructor called!" << std::endl;
        this->setTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm: Default destructor called!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    AForm::execute(executor);
    std::cout << Grades::ASCII_TREE << std::endl;
    std::string filename(this->getTarget() + "_shrubbery");
    std::ofstream fileout(filename.c_str());
    if (fileout.fail()) {
        std::cout << "Failed to open the file." << std::endl;
        return ;
    }
    fileout << Grades::ASCII_TREE;
    fileout.close();
}
