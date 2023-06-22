#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain: Default constructor called!" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain: Copy constructor called!" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain: Copy assignment operator called!" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        _ideas[i] = other._ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain: Default destructor called!" << std::endl;
}

std::string* Brain::getIdeas() {
    std::string* result =  new std::string[100];
    for (int i = 0; i < 100; i++)
        result[i] = this->_ideas[i];
    return result;
}

void Brain::setIdea(const int id, const std::string idea) {
    this->_ideas[id] = idea;
}

std::string Brain::getIdea(const int id) const{
    return this->_ideas[id];
}
