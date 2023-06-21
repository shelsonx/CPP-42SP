#include "Animal.hpp"
#include "Cat.hpp"

int main (void) {
    Animal animal;
    Cat cat;

    std::cout << animal.getType() << std::endl;
    animal.makeSound();

    std::cout << cat.getType() << std::endl;
    cat.makeSound();
}
