#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog: Default constructor called!" << std::endl;
    _type = "Dog";
}

Dog::Dog(const Dog& other) : Animal() {
    std::cout << "Dog: Copy constructor called!" << std::endl;
    _type = other.getType();
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog: Copy assignment operator called!" << std::endl;
    if (this != &other)
        _type = other.getType();
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog: Default destructor called!" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Bark, Bark..." << std::endl;
}
