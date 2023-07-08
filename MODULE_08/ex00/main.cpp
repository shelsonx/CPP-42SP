#include "easyfind.hpp"
#include <exception>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"


int main() {
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    {
        std::cout << GREEN << "Vector: " << std::endl << RESET;
        std::vector<int> numbers;
        numbers.push_back(5);
        numbers.push_back(3);
        numbers.push_back(5);

        try {
            std::vector<int>::iterator result = easyfind(numbers, 5);
            std::cout << "Founded " << *result << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::vector<int>::iterator result = easyfind(numbers, 42);
            std::cout << "Founded " << *result << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    {
        std::cout << GREEN << "List: " << std::endl << RESET;
        std::list<int> numbers;
        numbers.push_back(5);
        numbers.push_front(3);
        numbers.push_back(5);

        try {
            std::list<int>::iterator result = easyfind(numbers, 5);
            std::cout << "Founded " << *result << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::list<int>::iterator result = easyfind(numbers, 42);
            std::cout << "Founded " << *result << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
     std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    {
        std::cout << GREEN << "Deque: " << std::endl << RESET;
        std::deque<int> numbers;
        numbers.push_back(5);
        numbers.push_back(3);
        numbers.push_back(5);

        try {
            std::deque<int>::iterator result = easyfind(numbers, 5);
            std::cout << "Founded " << *result << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }

        try {
            std::deque<int>::iterator result = easyfind(numbers, 42);
            std::cout << "Founded " << *result << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;

    return 0;
}

