#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <list>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define BLUE	"\e[34m"

#define SIZE_FIVE 5
#define TEN_SIZE 10
#define TEN_THOUSAND 10000

int main(void) {
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Test Subject: " << RESET << std::endl;
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout 
        << GREEN << "Size: " << RED << sp.size() << std::endl
        << GREEN << "shortestSpan: " << RED 
        << sp.shortestSpan() << std::endl << RESET;
        std::cout
        << GREEN << "longestSpan: " << RED 
        << sp.longestSpan() << std::endl << RESET;
        std::cout << "Elements: " << std::endl;
        sp.displayValues();
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Test random " << TEN_SIZE << " numbers: " << RESET << std::endl;
    {
        std::srand(time(0));
        try {
            Span span = Span(TEN_SIZE);
            for (int i = 1; i <= TEN_SIZE; ++i)
                span.addNumber(i * (std::rand() % TEN_SIZE));
            std::cout
            << GREEN << "Size: " << RED << span.size() << std::endl
            << GREEN << "shortestSpan: " << RED 
            << span.shortestSpan() << std::endl << RESET;
            std::cout
            << GREEN << "longestSpan: " << RED 
            << span.longestSpan() << std::endl << RESET;
            std::cout << "Elements: " << std::endl;
            span.displayValues();
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Test " << TEN_THOUSAND << " numbers: " << RESET << std::endl;
    {
        std::srand(time(0));
        try {
            Span span = Span(TEN_THOUSAND);
            for (int i = 1; i <= TEN_THOUSAND; ++i)
                span.addNumber(i * (std::rand() % i));
            std::cout 
            << GREEN << "Size: " << RED << span.size() << std::endl
            << GREEN << "shortestSpan: " << RED 
            << span.shortestSpan() << std::endl << RESET;
            std::cout
            << GREEN << "longestSpan: " << RED 
            << span.longestSpan() << std::endl << RESET;
            std::cout << "Elements: " << std::endl;
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Test Add range  numbers: " << RESET << std::endl;
    {
        std::srand(time(0));
        std::list<int> numbers;
        try {
            Span span = Span(TEN_SIZE);
            for (int i = 1; i <= TEN_SIZE; ++i)
                numbers.push_back(i * (std::rand() % i));
            span.addNumbersRange(numbers.begin(), numbers.end());
            std::cout 
            << GREEN << "Size: " << RED << span.size() << std::endl
            << GREEN << "shortestSpan: " << RED 
            << span.shortestSpan() << std::endl << RESET;
            std::cout
            << GREEN << "longestSpan: " << RED 
            << span.longestSpan() << std::endl << RESET;
            std::cout << "Elements: " << std::endl;
            span.displayValues();
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Test max capacity: " << RESET << std::endl;
    {
        try {
            Span span = Span(SIZE_FIVE);
            for (int i = 1; i <= SIZE_FIVE; ++i)
                span.addNumber(i);
            span.addNumber(6);
        }
        catch (std::exception& e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }

    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Test impossible calculate spans 1: " << RESET << std::endl;
    {
        try {
            Span span = Span(1);
            span.addNumber(10);
            std::cout 
            << GREEN << "Size: " << RED << span.size() << std::endl;
            span.shortestSpan();
            span.longestSpan();
        }
        catch (std::exception& e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    std::cout << BLUE << "Test impossible calculate spans 2: " << RESET << std::endl;
    {
        try {
            Span span;
            std::cout 
            << GREEN << "Size: " << RED << span.size() << std::endl;
            span.shortestSpan();
            span.longestSpan();
        }
        catch (std::exception& e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    return 0;
}
