#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "WrongCat: Default constructor called!" << std::endl;
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
    std::cout << "WrongCat: Copy constructor called!" << std::endl;
    _type = other._type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat: Copy assignment operator called!" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat: Default destructor called!" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Meow, Meow..." << std::endl;
}
