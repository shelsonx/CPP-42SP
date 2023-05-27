#include "Zombie.hpp"

static bool check(int n)
{
    if (n <= 0)
    {
        std::cout << "Not allowed " << n 
        << " as a parameter. Try a positive value!" << std::endl;
        return false;
    }
    return true;
}

Zombie* zombieHorde(int N, std::string name )
{
    Zombie* zombies;

    if (!check(N))
        return NULL;
    zombies = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombies[i].setName(name);
    return zombies;
}
