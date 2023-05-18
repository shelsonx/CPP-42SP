#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        static int counter;
    public:
        Contact contacts[8];
        PhoneBook();
        void add(Contact contact);
};

#endif