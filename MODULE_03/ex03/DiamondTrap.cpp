#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << "DiamondTrap: Default constructor called" << std::endl;
    _name = "Default";
    _hitPoint = FragTrap::_hitPoint;
    _energyPoint = ScavTrap::_energyPoint;
    _attackDamage = FragTrap::_attackDamage;
    ClapTrap::_name = _name + "_clap_name";
}

DiamondTrap::DiamondTrap(const std::string name) {
    std::cout << "DiamondTrap: Constructor with name parameter called" << std::endl;
    _name = name;
    _hitPoint = FragTrap::_hitPoint;
    _energyPoint = ScavTrap::_energyPoint;
    _attackDamage = FragTrap::_attackDamage;
    ClapTrap::_name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(), ScavTrap(), FragTrap() {
    std::cout << "DiamondTrap: Copy constructor called" << std::endl;
    _name = other._name;
    _hitPoint = other._hitPoint;
    _energyPoint = other._energyPoint;
    _attackDamage = other._attackDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoint = other._hitPoint;
        _energyPoint = other._energyPoint;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap: Destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target ) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << " and my name ClapTrap is "
    << ClapTrap::getName() << std::endl;
}
