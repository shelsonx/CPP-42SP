#ifndef SPAN_HPP

#define SPAN
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <exception>

class  Span {
    public:
        Span(const unsigned int& size);
        Span();
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(const int& number);
        template<typename T>
        void addNumbersRange(const T& begin, const T& end);
        unsigned int shortestSpan(); 
        unsigned int longestSpan();
        void absoluteAdjacentDifference(std::vector<int>& spans);
        void displayValues();
        size_t size() const;

    private:
        std::vector<int> _elements;
        unsigned int _size;

        void _check();
};

template<typename T>
void Span::addNumbersRange(const T& begin, const T& end) {
    for (T it = begin; it != end; ++it) {
        addNumber(*it);
    }
}

#endif