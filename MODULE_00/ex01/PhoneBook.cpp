#include "PhoneBook.hpp"
#include <iomanip>

int PhoneBook::counter = -1;

PhoneBook::PhoneBook()
{
    counter++;
}

void PhoneBook::display_indexes()
{
     std::cout << std::setw(10) << "INDEX" 
        << "|" << std::setw(10) << "FIRST_NAME"
        << "|" << std::setw(10) << "LAST_NAME"
        << "|" << std::setw(10) << "NICKNAME"
        << "|" << std::endl;
}

void PhoneBook::display_indexes_all()
{
     std::cout << std::setw(10) << "INDEX"
        << "|" << std::setw(10) << "FIRST_NAME"
        << "|" << std::setw(10) << "LAST_NAME"
        << "|" << std::setw(10) << "NICKNAME"
        << "|" << std::setw(10) << "PHONE"
        << "|" << std::setw(10) << "SECRET"
        << "|" << std::endl;
}

void    PhoneBook::display_contacts()
{
    this->display_indexes();
    for (int i = 0; i < counter; i ++)
        this->contacts[i].display();
}

void    PhoneBook::search(int id)
{
    for (int i = 0; i < counter; i++)
    {
        if (contacts[i].get_id() == id)
        {
            display_indexes_all();
            contacts[i].display_all();
            return ;
        }
    }
    std::cout << "Contact not found!" << std::endl;
}

void PhoneBook::add(Contact contact)
{
    if (counter >= MAX_CONTACTS - 1)
        counter = MAX_CONTACTS - 1;
    contact.set_id(counter);
    this->contacts[counter] = contact;
    counter++;
}
