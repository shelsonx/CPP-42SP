#ifndef ITER_HPP

#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, const size_t &length, void (*f)(T &) ) {
    if (!array)
        return ;
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

template <typename T>
void iter(T const *array, const size_t& length, void (*f)(T const &) ) {
    if (!array)
        return ;
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

#endif