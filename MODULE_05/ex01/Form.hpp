#ifndef FORM_HPP

#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
    public:
        Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        Form(const std::string& name, 
            const int gradeSigned,
            const int gradeExecute);
        ~Form();

        const std::string& getName() const;
        const int& getGradeSigned() const;
        const int& getGradeExecute() const;
        
        void beSigned(const Bureaucrat& b);

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
        const int _gradeSigned;
        const int _gradeExecute;
        bool _isSigned;
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif