#ifndef FIXED_HPP

#define FIXED_HPP
#include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
    
        int getRawBits() const;
        void setRawBits(const int integerPart);

    private:
        int _integerPart;
        static const int _fractionalPart;
};

#endif