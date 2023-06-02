#include "Zombie.hpp"

int main()
{
    Zombie z0("Foo0");
    z0.announce();

    Zombie *z1 = newZombie("Foo");
    z1->announce();
    
    randomChump("Bar");
    
    delete z1;
}
