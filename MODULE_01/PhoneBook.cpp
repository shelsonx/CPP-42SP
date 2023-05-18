#include "PhoneBook.hpp"

int PhoneBook::counter = -1;

PhoneBook::PhoneBook()
{
    counter++;
}

void PhoneBook::add(Contact contact)
{
    this->contacts[counter] = contact;
    this->contacts[counter].set_id(counter);
}
