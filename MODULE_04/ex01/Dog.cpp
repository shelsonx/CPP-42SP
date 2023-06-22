#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog: Default constructor called!" << std::endl;
    _type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal() {
    std::cout << "Dog: Copy constructor called!" << std::endl;
    _type = other.getType();
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog: Copy assignment operator called!" << std::endl;
    if (this != &other) {
        _type = other.getType();
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog: Default destructor called!" << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Bark, Bark..." << std::endl;
}
