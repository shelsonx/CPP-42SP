#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <iostream>

class ClapTrap {
    public:
        ClapTrap(const std::string name);
        ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target );
        void takeDamge( unsigned int amount );
        void beRepaired( unsigned amount);
    private:
        std::string _name;
        int _hitPoint;
        int _energyPoint;
        int _attackDamage;
};

#endif