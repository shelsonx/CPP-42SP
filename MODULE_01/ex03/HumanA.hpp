#ifndef HUMAN_A
#define HUMAN_A

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA();
        HumanA(const std::string name, Weapon& weapon);
        void attack(void);
    private:
        Weapon& _weapon;
        std::string _name;
};

#endif
