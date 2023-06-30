#ifndef SHRUBBERYCREATIONFORM_HPP

#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class Grades {
    public:
        static const int SIGN;
        static const int EXECUTE;
        static const std::string ASCII_TREE;
};

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm(const std::string& target);

        void execute(Bureaucrat const & executor) const;

};

#endif