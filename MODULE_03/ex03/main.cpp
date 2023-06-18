#include "DiamondTrap.hpp"

int main(void)
{
    ClapTrap ct("Mr. Roboot 1");
    ScavTrap st("Mr. Roboot 2");
    FragTrap ft("Mr. Roboot 3");
    DiamondTrap dt("Monster");

    dt.attack(ct.getName());
    std::cout << std::endl;
    dt.takeDamage(5);
    std::cout << std::endl;
    dt.attack(st.getName());
    std::cout << std::endl;
    dt.beRepaired(1);
    std::cout << std::endl;
    dt.attack(ft.getName());
    std::cout << std::endl;
    dt.whoAmI();
    std::cout << std::endl;
}
