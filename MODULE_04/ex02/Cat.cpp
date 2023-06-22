#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat: Default constructor called!" << std::endl;
    _type = "Cat";
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal() {
    std::cout << "Cat: Copy constructor called!" << std::endl;
    _type = other._type;
    this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat: Copy assignment operator called!" << std::endl;
    if (this != &other) {
        _type = other._type;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat: Default destructor called!" << std::endl;
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Meow, Meow..." << std::endl;
}

Brain* Cat::getBrain() const {
    return this->brain;
}

void Cat::setBrain(const Brain& brain) {
    delete this->brain;
    this->brain = new Brain(brain);
}
