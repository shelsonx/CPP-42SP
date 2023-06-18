#ifndef FRAGTRAP

#define FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap {
    public:
        FragTrap(const std::string name);
        FragTrap();
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        void highFivesGuys(void);
    
    private:
};

#endif