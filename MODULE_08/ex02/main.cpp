#include "MutantStack.hpp"
#include <iomanip>
#include <list>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define BLUE	"\e[34m"

int main(void)
{
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Test Subject Mutante Stack: " << RESET << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "{\n   Top:" << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "   Size: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
                std::cout << std::endl << "   numbers: ";

        while (it != ite)
        {
            std::cout << *it;
            if (it < ite - 1)
                std::cout << ", ";
            ++it;
        }

        std::stack<int> s(mstack);

        std::cout << "\n}\n" << std::endl;
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Test Subject List: " << RESET << std::endl;
    {
        size_t i = 1;
        std::list<int> list;
    
        list.push_back(5);
        list.push_back(17);
        std::cout << "{\n   Top:" << list.back() << std::endl;
        list.pop_back();
        std::cout << "   Size: " << list.size() << std::endl;
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);
        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();
        ++it;
        --it;
        std::cout << std::endl << "   numbers: ";
        while (it != ite)
        {
            std::cout << *it;
            if (i++ < list.size())
                std::cout << ", ";
            ++it;
        }
        std::cout << "\n}\n" << std::endl;
    }
    std::cout << BLUE << "Test reverse iterator and not const it: " << RESET << std::endl;
    {
        MutantStack<int> ms;
        ms.push(2);
        ms.push(3);
        ms.push(5);
        ms.push(7);

        MutantStack<int>::reverse_iterator it = ms.rbegin();
        MutantStack<int>::reverse_iterator ite = ms.rend();
        *it = 9;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Test iterator and const it: " << RESET << std::endl;
    {
        MutantStack<int> ms;
        ms.push(2);
        ms.push(3);
        ms.push(5);
        ms.push(7);

        MutantStack<int>::const_iterator it = ms.begin();
        MutantStack<int>::const_iterator ite = ms.end();
        //*it = 9; //Se descomentar, não funciona por que it é const_iterator.
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    return 0;
}
