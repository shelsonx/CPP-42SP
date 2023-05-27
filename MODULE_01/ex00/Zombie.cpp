#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}

std::string Zombie::getName(void)
{
    return this->_name;
}