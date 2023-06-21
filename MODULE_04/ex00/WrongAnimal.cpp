#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal: Default constructor called!" << std::endl;
    _type = "Generic WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "WrongAnimal: Copy constructor called!" << std::endl;
    _type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal: Copy assignment operator called!" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: Default destructor called!" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->_type;
}

void WrongAnimal::makeSound() const{
    std::cout << "Generic Sound!" << std::endl;
}
