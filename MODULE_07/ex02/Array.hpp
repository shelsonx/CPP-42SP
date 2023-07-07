#ifndef ARRAY_HPP

#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array {
    public:
        Array(const unsigned int& n);
        Array();
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](const unsigned int& n) const;
        const unsigned int& size() const;

    private:
        T* _elements;
        unsigned int _n;
};

template<typename T>
Array<T>::Array(): _elements(0), _n(0){
    std::cout << "Default Constructor Called" << std::endl;
}

template<typename T>
Array<T>::Array(const unsigned int& n):_elements(new T[n]), _n(n) {
    std::cout << "Parameter Constructor Called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array& other) {
    std::cout << "Copy Constructor Called" << std::endl;
    *this = other;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    std::cout << "Copy Assignment Constructor Called" << std::endl;
    this->_n = other._n;
    delete[] this->_elements;
    this->_elements = new T[_n];
    for (unsigned int i = 0; i < this->_n; i++)
        this->_elements[i] = other._elements[i];
    return *this;
}

template<typename T>
Array<T>::~Array() {
    std::cout << "Destructor Constructor Called" << std::endl;
    delete[] this->_elements;
}

template<typename T>
T& Array<T>::operator[](const unsigned int& n) const {
    if (n >= this->_n)
        throw std::out_of_range("Index is out of bounds\n");
    return this->_elements[n];
}

template<typename T>
const unsigned int& Array<T>::size() const {
    return this->_n;
}
#endif