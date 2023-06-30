#ifndef PRESIDENTIALPARDONFORM_HPP

#define PRESIDENTIALPARDONFORM_HPP

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class GradesPresidential {
    public:
        static const int SIGN;
        static const int EXECUTE;
};

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        PresidentialPardonForm(const std::string& target);

        void execute(Bureaucrat const & executor) const;
};

#endif