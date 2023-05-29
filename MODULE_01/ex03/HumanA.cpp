#include "HumanA.hpp"

HumanA::HumanA(){}

HumanA::HumanA(const std::string name, Weapon& weapon)
{
    this->_name = name;
    this->_weapon = &weapon;
}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their "
    << (*this->_weapon).getType() << std::endl;
}
