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

std::string Contact::format_length(std::string field)
{
    std::string replaced;

    replaced = field;
    if (field.length() > 10)
        replaced = field.substr(0, 9) + ".";
    return replaced;
}

void Contact::display()
{
    std::cout << std::setw(10) << this->id
        << "|" << std::setw(10) << this->format_length(this->first_name)
        << "|" << std::setw(10) << this->format_length(this->last_name)
        << "|" << std::setw(10) << this->format_length(this->nickname)
        << "|" << std::setw(10) << std::endl;
}

void Contact::display_all()
{
    std::cout << std::setw(10) << this->id
        << "|" << std::setw(10) << this->format_length(this->first_name)
        << "|" << std::setw(10) << this->format_length(this->last_name)
        << "|" << std::setw(10) << this->format_length(this->nickname)
        << "|" << std::setw(10) << this->format_length(this->phone_number)
        << "|" << std::setw(10) << this->format_length(this->darkest_secret)
        << "|"  << std::setw(10) << std::endl;
}
