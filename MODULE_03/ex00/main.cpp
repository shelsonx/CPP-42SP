#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap ct("first");

    ct.attack("other");
    ct.takeDamage(2);
    ct.takeDamage(1);
    ct.takeDamage(5);
    ct.attack("other");
    ct.beRepaired(2);
    ct.takeDamage(3);
    ct.beRepaired(3);
    ct.beRepaired(1);
    ct.attack("other");
}
