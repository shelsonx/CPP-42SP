#include "Contact.hpp"
#include <iomanip>

Contact::Contact(
    std::string first_name, 
    std::string last_name, 
    std::string nickname, 
    std::string phone_number,
    std::string darkest_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

Contact::Contact(){};

int Contact::get_id()
{
    return this->id;
}

void Contact::set_id(int id)
{
    this->id = id;
}

void Contact::display()
{
    std::cout << std::setw(10) << this->id
        << "|" << std::setw(10) << this->first_name
        << "|" << std::setw(10) << this->last_name
        << "|" << std::setw(10) << this->nickname 
        << "|" << std::endl;
}

void Contact::display_all()
{
    std::cout << std::setw(10) << this->id
        << "|" << std::setw(10) << this->first_name
        << "|" << std::setw(10) << this->last_name
        << "|" << std::setw(10) << this->nickname
        << "|" << std::setw(10) << this->phone_number
        << "|" << std::setw(10) << this->darkest_secret 
        << "|" << std::endl;
}
