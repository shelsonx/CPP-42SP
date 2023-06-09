#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string.h>

#define MAX_CONTACTS 8

class Contact {
    private:
        int id;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact();
        Contact(std::string, std::string, std::string, std::string, std::string);
        int  get_id();
        void set_id(int);
        void display();
        void display_all();
        std::string format_length(std::string);
};

#endif