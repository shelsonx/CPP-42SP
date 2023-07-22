#ifndef PMERGEME

#define PMERGEME

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <utility>

class PmergeMe {
    public:
        PmergeMe(int size, char **argv);
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void sort();
        void sort(int size, char **argv);
        void setContainers(int size, char **argv);
        int stoi(std::string str);
        bool isValidInput(std::string str);
        template <typename T>
        void displayRawNumbers(const T& begin, const T& end);
    
    private:
        std::vector<int> _vNumbers;
        std::deque<int> _dNumbers;

        std::vector<std::pair<int, int> > splitPairsVector();
        void sortSecondElementVector(std::vector<std::pair<int, int> >& pairs);
        void splitLeftRightVector(const std::vector<std::pair<int, int> >& pairs, 
            std::vector<int>& left, 
            std::vector<int>& right);
        void insertNumbersVector(std::vector<int>::iterator it_left);
        void insertionSortVector(std::vector<int>& left, std::vector<int>& right);

        void removeExtra();
        
};

template <typename T>
void PmergeMe::displayRawNumbers(const T& begin, const T& end) {
    for (T it = begin; it != end; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

#endif