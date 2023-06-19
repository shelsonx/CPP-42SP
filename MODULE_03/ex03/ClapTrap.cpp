#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name) {
    std::cout << "ClapTrap: Constructor with name parameter called" << std::endl;
    this->_name = name;
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap: Default constructor called" << std::endl;
    this->_name = "Default";
    this->_hitPoint = 10;
    this->_energyPoint = 10;
    this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap: Copy constructor called" << std::endl;
    this->_name = other._name;
    this->_hitPoint = other._hitPoint;
    this->_energyPoint = other._energyPoint;
    this->_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap: Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap: Destructor called" << std::endl;
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
    this->_energyPoint--;
    std::cout 
        << "ClapTrap " << this->_name << " attacks, " << target
        << " causing " << this->_attackDamage << " points of damage!"
        << std::endl;
}

void ClapTrap::beRepaired( unsigned amount) {
    if (this->_hitPoint <= 0 )
    {
        std::cout << "It cannot recover, for it is dead." << std::endl;
        return ;
    }
    if (this->_energyPoint <= 0)
    {
        std::cout << "It doesn't have enough energy to recover." << std::endl;
        return ;
    }
    if (this->_hitPoint + amount >= 10)
        this->_hitPoint = 10;
    else
        this->_hitPoint += amount;
    this->_energyPoint--;
    std::cout 
        << "ClapTrap " << this->_name << " recover, " << amount
        << " hit point(s), current hit points= " << this->_hitPoint << " point(s) "
        << "and " << this->_energyPoint << " energy point(s)." << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
    if ((unsigned int) this->_hitPoint < amount)
        this->_hitPoint = 0;
    else
        this->_hitPoint -= amount;
    std::cout 
        << "ClapTrap " << this->_name << " has taken " << amount
        << " damage current hit points= " << this->_hitPoint << " point(s) "
        << "and " << this->_energyPoint << " energy point(s)." << std::endl;
}

std::string ClapTrap::getName() {
    return this->_name;
}
