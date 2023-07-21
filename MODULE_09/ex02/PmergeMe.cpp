#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int size, char **argv) {
    setContainers(size, argv);
}
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->_vNumbers = other._vNumbers;
        this->_dNumbers = other._dNumbers;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

int PmergeMe::stoi(std::string str ) {
    int i;

    std::istringstream(str) >> i;
    if (i == 0 && str.compare("0") != 0)
		return -1;
	return i;
}

bool PmergeMe::isValidInput(std::string str) {
    std::string::iterator it;
    for (it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it))
            return false;
    }
    if (stoi(str) < 0 )
        return false;
    return true;
}

void PmergeMe::setContainers(int size, char **argv) {
    if (size <= 1)
        throw std::runtime_error("Insufficient elements.");
    
    for (int i = 1; i < size; ++i) {
        if (!isValidInput(argv[i]))
            throw std::runtime_error("Invalid input.");
        this->_vNumbers.push_back(stoi(argv[i]));
        this->_dNumbers.push_back(stoi(argv[i]));
    }
}

void PmergeMe::addExtravalues(std::vector<int>& merged, std::vector<int>& subVector, size_t position) {
    while (position < subVector.size())
        merged.push_back(subVector[position++]);
}

void PmergeMe::insertionSort(std::vector<int>& arr, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; i++) {
        int current = arr[i];
        size_t j = i - 1;
        while (j >= left && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

std::vector<int> PmergeMe::merge(std::vector<int>& leftArray, std::vector<int>& rightArray) {
    std::vector<int> merged;
    size_t indexLeft = 0, indexRight = 0;

    while (indexLeft < leftArray.size() && indexRight < rightArray.size()) {
        if (leftArray[indexLeft] <= rightArray[indexRight]) {
            merged.push_back(leftArray[indexLeft]);
            indexLeft++;
        }
        else {
            merged.push_back(rightArray[indexRight]);
            indexRight++;
        }
    }
    addExtravalues(merged, leftArray, indexLeft);
    addExtravalues(merged, rightArray, indexRight);

    return merged;
}

std::vector<int> PmergeMe::mergeInsertSort(std::vector<int>& numbers) {
    size_t size = numbers.size();
   
    if (size == 1)
        return numbers;
    
    if (size == _vNumbers.size() / 2) {
        insertionSort(numbers, 0, size -1);
        return numbers;
    }
    std::vector<int> leftVector(numbers.begin(), numbers.begin() + size / 2);
    std::vector<int> rightVector(numbers.begin() + size / 2, numbers.end());

    leftVector = mergeInsertSort(leftVector);
    rightVector = mergeInsertSort(rightVector);

    return merge(leftVector, rightVector);
}

void PmergeMe::sort() {
    _vNumbers = mergeInsertSort(_vNumbers);
    displayRawNumbers(_vNumbers.begin(), _vNumbers.end());
}

void PmergeMe::sort(int size, char **argv) {
    setContainers(size, argv);
    sort();
}
