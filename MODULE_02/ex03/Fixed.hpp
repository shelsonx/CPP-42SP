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

        bool operator>(const Fixed& other);
        bool operator<(const Fixed& other);
        bool operator>=(const Fixed& other);
        bool operator<=(const Fixed& other);
        bool operator==(const Fixed& other);
        bool operator!=(const Fixed& other);

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        static Fixed& min(Fixed& lhs, Fixed& rhs);
        static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
        static Fixed& max(Fixed& lhs, Fixed& rhs);
        static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

    private:
        int _value;
        static const int _factorScale;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif