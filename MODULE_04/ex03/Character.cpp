#include "Character.hpp"

Character::Character(const std::string& name) {
    std::cout << "Character: type with parameter constructor called!" << std::endl;
    this->_name = name;
    this->initInventory();
}

Character::Character() {
    std::cout << "Character: Default constructor called!" << std::endl;
    this->_name = "Default";
    this->initInventory();
}

Character::Character(const Character& other) {
    std::cout << "Character: Copy constructor called!" << std::endl;
    *this = other;
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character: Copy assignment operator called!" << std::endl;
    if (this != &other) {
        this->_name = other.getName();
        this->emptyInventory();
        for (int i = 0; i < MAX_SLOTS; i++) {
            this->_inventory[i] = other._inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character: Default destructor called!" << std::endl;
    this->emptyInventory();
}

void Character::equip(AMateria* m) {
    if (!m) {
        std::cout << m << " Not valid!" << std::endl;
        return ;
    }
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m;
            std::cout << "successfully equipped!" << std::endl;
            return ;
        }
    }
    std::cout << "Full inventory!" << std::endl;
}

void Character::unequip(int idx) {
    if (this->_inventory[idx] == NULL) {
        std::cout << idx << " Not found!" << std::endl;
        return ;
    }
    if (idx < 0 || idx >= MAX_SLOTS) {
        std::cout << idx << " out of range!" << std::endl;
        return ;
    }
    this->_inventory[idx] = NULL;
    std::cout << idx << "Successfully unequipped!" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
    if (this->_inventory[idx] == NULL) {
        std::cout << idx << " Not found!" << std::endl;
        return ;
    }
    if (idx < 0 || idx >= MAX_SLOTS) {
        std::cout << idx << " out of range!" << std::endl;
        return ;
    }
    this->_inventory[idx]->use(target);
}

std::string const & Character::getName() const {
    return this->_name;
}

void Character::initInventory() {
    for (int i = 0; i < MAX_SLOTS; i++)
        this->_inventory[i] = NULL;
}

void Character::emptyInventory() {
    for (int i = 0; i < MAX_SLOTS; i++) {
        delete this->_inventory[i];
        this->_inventory[i] = NULL;
    }
}
