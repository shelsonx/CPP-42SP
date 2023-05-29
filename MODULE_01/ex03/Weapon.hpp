#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon {
    public:
        Weapon();
        Weapon(const std::string);
        const std::string& getType(void);
        void setType(const std::string newType);
    private:
        std::string _type;
};
#endif