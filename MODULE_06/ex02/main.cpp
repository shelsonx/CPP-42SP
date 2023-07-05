#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base* generate(void) {
    int option;

    std::srand(time(0));
    option = std::rand() % 3;

    switch (option)
    {
        case 0:
            return new A;
            break;
        case 1:
            return new B;
            break;
        case 2:
            return new C;
            break;
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A* >(p))
        std::cout << "Pointer to instance A" << std::endl;
    else if (dynamic_cast<B* >(p))
        std::cout << "Pointer to instance B" << std::endl;
    else if (dynamic_cast<C* >(p))
        std::cout << "Pointer to instance C" << std::endl;
    else
        std::cout << "instance class unknown" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A& >(p);
        if (&a == &p)
            std::cout << "Pointer to A" << std::endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << " To A" << std::endl;
    }

    try {
        B& b = dynamic_cast<B& >(p);
        if (&b == &p)
            std::cout << "Pointer to B" << std::endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << " To B" << std::endl;
    }

    try {
        C& c = dynamic_cast<C& >(p);
        if (&c == &p)
            std::cout << "Pointer to C" << std::endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << " To C" << std::endl;
    }
}

int main(void) {
    Base* base;

    base = generate();
    identify(base);
    identify(*base);

    delete base;
}
