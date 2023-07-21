#ifndef PMERGEME

#define PMERGEME

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <exception>
#include <stdexcept>


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

        void insertionSort(std::vector<int>& arr, size_t left, size_t right);
        std::vector<int> merge(std::vector<int>& leftArray, std::vector<int>& rightArray);
        std::vector<int> mergeInsertSort(std::vector<int>& numbers);
        void addExtravalues(std::vector<int>& merged, std::vector<int>& subVector, size_t start);
};

template <typename T>
void PmergeMe::displayRawNumbers(const T& begin, const T& end) {
    for (T it = begin; it != end; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

#endif