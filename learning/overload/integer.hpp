#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <iostream>

class Integer
{
    public:
        Integer(int const n);
        ~Integer();

        int getValue() const;

        Integer & operator=(Integer const & rhs);
        Integer operator+(Integer const & rhs) const;
    
    private:
        int _n;
};
std::ostream & operator<<(std::ostream & o, Integer const & rhs);

#endif