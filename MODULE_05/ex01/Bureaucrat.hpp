#ifndef BUREAUCRAT_HPP

#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        Bureaucrat(const std::string& name, const int grade);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;

        void increment();
        void decrement();
        void signForm(Form& form) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string _name;
        int _grade;

        static const int highestGrade = 1;
        static const int lowestGrade = 150;

        void checkGrade(const int grade) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif