#include <iomanip>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main (void) {
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << meta->getType() << " " << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete i;
        delete j;
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    {
        const WrongAnimal *wanimal = new WrongAnimal();
        const WrongAnimal *wcat = new WrongCat();
        std::cout << wcat->getType() << " " << std::endl;
        std::cout << wanimal->getType() << " " << std::endl;
        wcat->makeSound();
        wanimal->makeSound();

        delete wcat;
        delete wanimal;
    }
    return 0;
}
