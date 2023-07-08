#include "easyfind.hpp"
#include <exception>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define TARGET 5
#define TARGET_NOT_FOUND 42


int main() {
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    {
        std::cout << GREEN << "Vector: " << std::endl << RESET;
        std::vector<int> numbers;
        numbers.push_back(5);
        numbers.push_back(3);
        numbers.push_back(5);

        try {
            std::vector<int>::iterator result = easyfind(numbers, TARGET);
            std::cout << "target " << GREEN << TARGET << RESET
            << " found at index: " << RED << std::distance(numbers.begin(), result) 
            << std::endl << RESET;
        } catch (std::exception& e) {
            std::cout << RED << e.what() << " :" << TARGET_NOT_FOUND << std::endl << RESET;
        }

        try {
            std::vector<int>::iterator result = easyfind(numbers, TARGET_NOT_FOUND);
            std::cout << "Founded " << *result << std::endl;
        } catch (std::exception& e) {
            std::cout << RED << e.what() << " :" << TARGET_NOT_FOUND << std::endl << RESET;
        }
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    {
        std::cout << GREEN << "List: " << std::endl << RESET;
        std::list<int> numbers;
        numbers.push_back(3);
        numbers.push_back(5);
        numbers.push_back(5);

        try {
            std::list<int>::iterator result = easyfind(numbers, TARGET);
            std::cout << "target " << GREEN << TARGET << RESET
            << " found at index: " << RED << std::distance(numbers.begin(), result) 
            << std::endl << RESET;
        } catch (std::exception& e) {
            std::cout << RED << e.what() << " :" << TARGET_NOT_FOUND << std::endl << RESET;
        }

        try {
            std::list<int>::iterator result = easyfind(numbers, TARGET_NOT_FOUND);
            std::cout << "Founded " << *result << std::endl;
        } catch (std::exception& e) {
            std::cout << RED << e.what() << " :" << TARGET_NOT_FOUND << std::endl << RESET;
        }
    }
     std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    {
        std::cout << GREEN << "Deque: " << std::endl << RESET;
        std::deque<int> numbers;
        numbers.push_back(3);
        numbers.push_back(3);
        numbers.push_back(5);

        try {
            std::deque<int>::iterator result = easyfind(numbers, TARGET);
            std::cout << "target " << GREEN << TARGET << RESET
            << " found at index: " << RED << std::distance(numbers.begin(), result) 
            << std::endl << RESET;
        } catch (std::exception& e) {
            std::cout << RED << e.what() << " :" << TARGET_NOT_FOUND << std::endl << RESET;
        }

        try {
            std::deque<int>::iterator result = easyfind(numbers, TARGET_NOT_FOUND);
            std::cout << "Founded " << *result << std::endl;
        } catch (std::exception& e) {
            std::cout << RED << e.what() << " :" << TARGET_NOT_FOUND << std::endl << RESET;
        }
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;

    return 0;
}

