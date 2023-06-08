#include "Fixed.hpp"

const int Fixed::_factorScale = 8;

Fixed::Fixed(const int value) {
    this->_value = value << Fixed::_factorScale;;
}

Fixed::Fixed(const float value) {
    this->_value = (roundf(value * (1 << this->_factorScale)));
}

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed& other): _value(other._value) {}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_value = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed& other){
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other){
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other){
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other){
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other){
    return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const{
    float result = this->toFloat() + other.toFloat();
    return Fixed(result);
}

Fixed Fixed::operator-(const Fixed& other) const{
    float result = this->toFloat() - other.toFloat();
    return Fixed(result);
}

Fixed Fixed::operator*(const Fixed& other) const{
    float result = (this->toFloat() * other.toFloat());
    return Fixed(result);
}

Fixed Fixed::operator/(const Fixed& other) const{
    float result = (this->toFloat() / other.toFloat());
    return Fixed(result);
}

Fixed& Fixed::operator++(void) {
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed result = *this;
    ++(*this);
    return result;
}

Fixed& Fixed::operator--(void) {
    --_value;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed result = *this;
    --(*this);
    return result;
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
    return (lhs < rhs ? lhs : rhs);
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
    return (lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs);
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
    return (lhs > rhs ? lhs : rhs);
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
    return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}
