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

void PmergeMe::sort() {
    //DEBUG
    displayRawNumbers(_vNumbers.begin(), _vNumbers.end());
    displayRawNumbers(_dNumbers.begin(), _dNumbers.end());
}

void PmergeMe::sort(int size, char **argv) {
    setContainers(size, argv);
    displayRawNumbers(_vNumbers.begin(), _vNumbers.end());
    displayRawNumbers(_dNumbers.begin(), _dNumbers.end());
}
