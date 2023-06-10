#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) {
    this->_name = name;
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap() {
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    this->_name = other._name;
    this->_hitPoint = other._hitPoint;
    this->_energyPoint = other._energyPoint;
    this->_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

