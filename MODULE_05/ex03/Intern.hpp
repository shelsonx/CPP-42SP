#ifndef INTERN_HPP

#define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string name, const std::string target);

        AForm* shrubberyCreationForm(const std::string target) const;
        AForm* robotomyRequestForm(const std::string target) const;
        AForm* presidentialPardonForm(const std::string target) const;

        class FormDoesNotExists : public std::exception {
            public:
                virtual const char* what() const throw();
        };
    
    private:
        static const int SIZE  = 3;
        AForm* forms[SIZE];

        int getIndexForm(const std::string name) const;

};

#endif