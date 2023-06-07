#include "Fixed.hpp"

const int Fixed::_factorScale = 8;

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = (value << _factorScale);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = (roundf(value * (1 << this->_factorScale)));
}

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const{
    return this->_value;
}

void Fixed::setRawBits( const int value)
{
    this->_value = value;
}

float Fixed::toFloat() const
{
    return (float) this->_value / (1 << _factorScale);
}

int Fixed::toInt() const{
    return this->_value >> _factorScale;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
