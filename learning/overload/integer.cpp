#include "integer.hpp"

Integer::Integer(const int n): _n(n)
{
    std::cout << "Constructor called with value " << n << std::endl;
}

Integer::~Integer()
{
    std::cout << "Destructor called with value " << std::endl;
}

int Integer::getValue() const {
    return this->_n;
}

Integer & Integer::operator=(const Integer &rhs){
    std::cout << "Assignment operator called from " << this->_n;
    std::cout << " to " << rhs.getValue() << std::endl;
    this->_n = rhs.getValue();
    return *this;
}

Integer Integer::operator+(const Integer & rhs) const {
    std::cout << "Addition operator called with " << this->_n;
    std::cout << " and " << rhs.getValue();
    return Integer(this->_n + rhs.getValue());
}

std::ostream & operator<<(std::ostream & o, Integer const & rhs){
    o << rhs.getValue();
    return o;
}
