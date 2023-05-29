#ifndef HUMAN_B
#define HUMAN_B

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB();
        HumanB(const std::string name);
        void attack(void);
        void setWeapon(Weapon& weapon);
    private:
        Weapon* _weapon;
        std::string _name;
};

#endif