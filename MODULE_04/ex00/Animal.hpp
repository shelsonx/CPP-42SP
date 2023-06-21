#ifndef ANIMAL_HPP

#define ANIMAL_HPP

#include <iostream>

class Animal {
    public:
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        ~Animal();

        std::string getType() const;
    private:
        std::string _type;

};

#endif