#include <iomanip>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main (void) {
    Brain b1;
    std::string* ideas;

    b1.setIdea(0, "banana");
    b1.setIdea(1, "uva");
    std::cout << b1.getIdea(0) << std::endl;
    std::cout << b1.getIdea(1) << std::endl;
    ideas = b1.getIdeas();
    std::cout << ideas[1] << std::endl;

    delete [] ideas;
    return 0;
}
