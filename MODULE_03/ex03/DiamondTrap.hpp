#ifndef DIAMONDTRAP

#define DIAMONDTRAP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    public:
        DiamondTrap(const std::string name);
        DiamondTrap();
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap();

        void whoAmI();
        void attack(const std::string& target );

    private:
        std::string _name;
};

#endif
