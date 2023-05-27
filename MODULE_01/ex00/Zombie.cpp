#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << " destroyd" << std::endl;
}
