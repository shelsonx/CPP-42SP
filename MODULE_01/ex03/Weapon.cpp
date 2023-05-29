#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
    this->_type = type;
}

const std::string& Weapon::getType(void)
{
    std::string& typeRef = this->_type;
    return typeRef;
}

void Weapon::setType(const std::string newType)
{
    this->_type = newType;
}
