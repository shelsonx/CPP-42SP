#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() {
    std::cout << "Ice: Default constructor called!" << std::endl;
    _type = "ice";
}

Ice::Ice(const Ice& other) : AMateria() {
    std::cout << "Ice: Copy constructor called!" << std::endl;
    _type = other._type;
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << "Ice: Copy assignment operator called!" << std::endl;
    _type = other._type;
    return *this;
}

Ice::~Ice() {
    std::cout << "Ice: Default destructor called!" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice();
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " * " << std::endl;
}