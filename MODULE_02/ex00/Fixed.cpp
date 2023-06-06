#include "Fixed.hpp"

const int Fixed::_fractionalPart = 8;

Fixed::Fixed() : _integerPart(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): _integerPart(other._integerPart) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_integerPart = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_integerPart;
}

void Fixed::setRawBits( const int integerPart)
{
    this->_integerPart = integerPart;
}
