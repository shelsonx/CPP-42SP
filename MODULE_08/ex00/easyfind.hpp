#ifndef EASYFIND_HPP

#define EASYFIND
#include <iostream>
#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::const_iterator easyfind(const T& container, int target) {

    typename T::const_iterator it = std::find(
        container.begin(), 
        container.end(),
        target);

    if (it == container.end())
        throw std::runtime_error("Target not found");
    return it;
}

template<typename T>
typename T::iterator easyfind(T& container, int target) {

    typename T::iterator it = std::find(
        container.begin(), 
        container.end(),
        target);

    if (it == container.end())
        throw std::runtime_error("Target not found");
    return it;
}

#endif