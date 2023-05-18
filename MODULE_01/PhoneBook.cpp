#include "PhoneBook.hpp"

void PhoneBook::add(Contact contact)
{
    //this->contacts[this->counter] = contact;
    contact.set_id(this->counter);
    this->counter++;
}
