#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap: Default constructor called" << std::endl;
    _name = "Default";
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string name) {
    std::cout << "ScavTrap: Constructor with name parameter called" << std::endl;
    _name = name;
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
    std::cout << "ScavTrap: Copy constructor called" << std::endl;
    _name = other._name;
    _hitPoint = other._hitPoint;
    _energyPoint = other._hitPoint;
    _attackDamage = other._attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavStrap: Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoint = other._hitPoint;
        _energyPoint = other._hitPoint;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target ) {
    if (this->_hitPoint <= 0) {
        std::cout << "all lives lost!" << std::endl;
        return ;
    }
    if (this->_energyPoint <= 0)
    {
        std::cout << "No energy to attack." << std::endl;
        return ;
    }
    this->_energyPoint--;
    std::cout 
        << "ScavTrap " << this->_name << " attacks, " << target
        << " causing " << this->_attackDamage << " points of damage!"
        << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "Gate keeper mode activate!" << std::endl;
}
