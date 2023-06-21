#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal: Default constructor called!" << std::endl;
    _type = "Generic Animal";
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal: Copy constructor called!" << std::endl;
    _type = other._type;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal: Copy assignment operator called!" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal: Default destructor called!" << std::endl;
}

std::string Animal::getType() const {
    return this->_type;
}

void Animal::makeSound() const{
    std::cout << "Generic Sound!" << std::endl;
}
