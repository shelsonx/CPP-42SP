#ifndef AFORM_HPP

#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        AForm(const std::string& name, 
            const int gradeSigned,
            const int gradeExecute);
        virtual ~AForm();

        const std::string& getName() const;
        const int& getGradeSigned() const;
        const int& getGradeExecute() const;
        const bool& isSigned() const;
        const std::string& getTarget() const;
        void setTarget(const std::string& target);
        
        void beSigned(const Bureaucrat& b);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    protected:
        std::string _target;

    private:
        const std::string _name;
        const int _gradeSigned;
        const int _gradeExecute;
        bool _isSigned;

        static const int highestGrade = 1;
        static const int lowestGrade = 150;

        void checkGrade(const int& grade) const;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif