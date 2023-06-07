#ifndef FIXED_HPP

#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed(const int value);
        Fixed(const float value);

        Fixed(void);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
    
        int getRawBits() const;
        void setRawBits(const int value);
        float toFloat() const;
        int toInt( void ) const;

    private:
        int _value;
        static const int _factorScale;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif