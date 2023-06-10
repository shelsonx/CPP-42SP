#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) {
    std::cout << "Constructor with name parameter called" << std::endl;
    this->_name = name;
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap() {
    std::cout << "Default constructor called" << std::endl;
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_name = other._name;
    this->_hitPoint = other._hitPoint;
    this->_energyPoint = other._energyPoint;
    this->_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target ) {
    if (this->_hitPoint <= 0) {
        std::cout << "all lives lost!" << std::endl;
        return ;
    }
    if (this->_energyPoint <= 0)
    {
        std::cout << "No energy to attack." << std::endl;
        return ;
    }
    std::cout 
        << "ClapTrap " << this->_name << " attacks, " << target
        << " causing " << this->_attackDamage << " points of damage!"
        << std::endl;
    this->_energyPoint--;
}
