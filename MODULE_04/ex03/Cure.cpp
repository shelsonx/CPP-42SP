#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() {
    std::cout << "Cure: Default constructor called!" << std::endl;
    _type = "cure";
}

Cure::Cure(const Cure& other) : AMateria() {
    std::cout << "Cure: Copy constructor called!" << std::endl;
    _type = other._type;
}

Cure& Cure::operator=(const Cure& other) {
    std::cout << "Cure: Copy assignment operator called!" << std::endl;
    _type = other._type;
    return *this;
}

Cure::~Cure() {
    std::cout << "Cure: Default destructor called!" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure();
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
