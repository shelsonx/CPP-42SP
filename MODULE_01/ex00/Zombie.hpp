#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        void setName(std::string name);
        void announce(void);
        std::string getName(void);
};

#endif
