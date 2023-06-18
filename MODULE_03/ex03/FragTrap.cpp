#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap: Default constructor called" << std::endl;
    _name = "Default";
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const std::string name) {
    std::cout << "FragTrap: Constructor with name parameter called" << std::endl;
    _name = name;
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap() {
    std::cout << "FragTrap: Copy constructor called" << std::endl;
    _name = other._name;
    _hitPoint = other._hitPoint;
    _energyPoint = other._energyPoint;
    _attackDamage = other._attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragStrap: Copy assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoint = other._hitPoint;
        _energyPoint = other._energyPoint;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: Destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "High five, guys!\xF0\x9F\x99\x8C" << std::endl;
}
