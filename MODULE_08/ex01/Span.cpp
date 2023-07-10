#include "Span.hpp"

Span::Span() :_size(0) {
    std::cout << "Default constructor called" << std::endl;
}

Span::Span(const Span& other) :_size(0) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Span& Span::operator=(const Span& other) {
    std::cout << "Copy assigment constructor called" << std::endl;
    if (this != &other) {
        this->_elements.clear();
        this->_elements.insert(
            this->_elements.end(),
            other._elements.begin(),
            other._elements.end());
    }
    return *this;
}

Span::Span(const unsigned int& size) :_size(size) {
    std::cout << "Parameter constructor called" << std::endl;
}

Span::~Span() {
    std::cout << "Destructor called" << std::endl;
}

void Span::addNumber(const int& number) {
    if (this->_elements.size() >= this->_size)
        throw std::overflow_error("Max capacity reached.");
    this->_elements.push_back(number);
}

void Span::absoluteAdjacentDifference(std::vector<int>& spans) {
    for (size_t i = 1; i < this->_elements.size(); ++i)
        spans[i - 1] = std::abs(this->_elements[i] - this->_elements[i - 1]);
}

void Span::_check() {
    if (this->_elements.size() <= 1) {
        throw std::runtime_error(
            "Insufficient number of elements to calculate spans.");
    }
}

unsigned int Span::shortestSpan() {
    std::vector<int> spans(this->_elements.size());

    this->_check();
    this->absoluteAdjacentDifference(spans);
    spans.pop_back();
    int result = *std::min_element(spans.begin(), spans.end());
    return result;
}

unsigned int Span::longestSpan() {
    std::vector<int> spans(this->_elements.size());

    this->_check();
    spans.pop_back();
    this->absoluteAdjacentDifference(spans);
    int result = *std::max_element(spans.begin(), spans.end());
    return result;
}

void Span::displayValues() {
    for (std::vector<int>::iterator it = _elements.begin(); 
        it != _elements.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

size_t Span::size() const {
    return this->_elements.size();
}
