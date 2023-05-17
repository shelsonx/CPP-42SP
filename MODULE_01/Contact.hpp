#ifndef CONTACT
# define CONTACT

#include <iostream>
#include <string.h>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact();
        Contact(std::string, std::string, std::string, std::string, std::string);
        void display();
};

#endif