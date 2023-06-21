#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat: Default constructor called!" << std::endl;
    _type = "Cat";
}

Cat::Cat(const Cat& other) : Animal() {
    std::cout << "Cat: Copy constructor called!" << std::endl;
    _type = other._type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat: Copy assignment operator called!" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat: Default destructor called!" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow, Meow..." << std::endl;
}
