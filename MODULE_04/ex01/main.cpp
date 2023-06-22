#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main (void) {
    Animal* animals[100];

    for (int i = 0; i < 50; i++) {
        std::cout << i << std::endl;
        animals[i] = new Dog();
    }
    for (int i = 50; i < 100; i++) {
        std::cout << i << std::endl;
        animals[i] = new Cat();
    }
    for (int i = 0; i < 100; i ++) {
        std::cout << i << std::endl;
        delete animals[i];
    }
    return 0;
}
