#include "Fixed.hpp"

int main( void ) {
    /* Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl; */
    Fixed a(2);
    Fixed b(3);
    std::cout << "Return: " << (a > b ? "true" : "false") << std::endl;
    std::cout << "Return: " << (a < b ? "true" : "false") << std::endl;
    std::cout << "Return: " << (a >= b ? "true" : "false") << std::endl;
    std::cout << "Return: " << (a <= b ? "true" : "false") << std::endl;
    std::cout << "Return: " << (a == b ? "true" : "false") << std::endl;
    std::cout << "Return: " << (a != b ? "true" : "false") << std::endl;

    std::cout << "equals: " << std::endl;
    a.setRawBits(3);
    b.setRawBits(3);
    std::cout << "Return: " << (a == b ? "true" : "false") << std::endl;
    std::cout << "Return: " << (a != b ? "true" : "false") << std::endl;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    return 0;
}