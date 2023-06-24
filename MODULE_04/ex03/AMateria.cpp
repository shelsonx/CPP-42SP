#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
    std::cout << "AMateria: type with parameter constructor called!" << std::endl;
    _type = type;
}

AMateria::AMateria() {
    std::cout << "AMateria: Default constructor called!" << std::endl;
     _type = "unknown";
}

AMateria::AMateria(const AMateria& other) {
    std::cout << "AMateria: Copy constructor called!" << std::endl;
    _type = other._type;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria: Copy assignment operator called!" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria: Default destructor called!" << std::endl;
}

std::string const & AMateria::getType() const {
    return this->_type;
}
