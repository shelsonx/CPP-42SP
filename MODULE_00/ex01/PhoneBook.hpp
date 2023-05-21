#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    private:
        static int counter;
        Contact contacts[MAX_CONTACTS];
    public:
        PhoneBook();
        void add(Contact contact);
        void search(int);
        void display_indexes();
        void display_indexes_all();
        void display_contacts();
};

#endif