#include "FragTrap.hpp"

int main(void)
{
    FragTrap ft("Mr. roboot");

    ft.attack("other");
    ft.takeDamage(5);
    ft.attack("other");
    ft.beRepaired(1);
    ft.attack("other");
    ft.highFivesGuys();
}
