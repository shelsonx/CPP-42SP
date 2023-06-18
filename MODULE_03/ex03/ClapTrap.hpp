#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
    public:
        ClapTrap(const std::string name);
        ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned amount);
        std::string getName();
    protected:
        std::string _name;
        int _hitPoint;
        int _energyPoint;
        int _attackDamage;
};

#endif