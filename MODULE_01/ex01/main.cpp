#include "Zombie.hpp"

int main()
{
    Zombie* zombies = zombieHorde(3, "Foo");

    for (int i = 0; i < 3; i++)
        zombies[i].announce();
    Zombie* zombies2 = zombieHorde(0, "Bar");
    Zombie* zombies3 = zombieHorde(-5, "Bar");
    Zombie* zombies4 = zombieHorde(1, "Bar");
    delete[] zombies;
    delete[] zombies4;
}
