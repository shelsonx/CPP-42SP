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

std::vector<std::pair<int, int> > PmergeMe::splitPairsVector() {
    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < _vNumbers.size(); i += 2) {
        if (_vNumbers[i] > _vNumbers[i + 1]) {
            pairs.push_back(std::make_pair(_vNumbers[i + 1], _vNumbers[i]));
        } else {
            pairs.push_back(std::make_pair(_vNumbers[i], _vNumbers[i + 1]));
        }
    }
    if (_vNumbers.size() % 2 != 0) {
        pairs.push_back(std::make_pair(_vNumbers.back(), -1));
    }
    return pairs;
}

void PmergeMe::sortSecondElementVector(std::vector<std::pair<int, int> >& pairs) {
    size_t size = pairs.size();

    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (pairs[j].second > pairs[j + 1].second) {
                std::swap(pairs[j], pairs[j + 1]);
            }
        }
    }
}

 void PmergeMe::splitLeftRightVector(const std::vector<std::pair<int, int> >& pairs, 
            std::vector<int>& left, 
            std::vector<int>& right) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        left.push_back(pairs[i].first);
        right.push_back(pairs[i].second);
    }
}

void PmergeMe::insertNumbersVector(std::vector<int>::iterator it_left) {
    std::vector<int>::iterator it_nums;

    for (it_nums = _vNumbers.begin(); it_nums <= _vNumbers.end(); it_nums++)
    {
        if (*it_left <= *it_nums)
        {
            _vNumbers.insert(it_nums, *it_left);
            break ;
        }
        else if (it_nums == _vNumbers.end()) {
            _vNumbers.push_back(*it_left);
            break;
        }
    }
}

void PmergeMe::removeExtra() {
    if (_vNumbers[0] < 0)
        _vNumbers.erase(_vNumbers.begin());  
}

void PmergeMe::insertionSortVector(std::vector<int>& left, std::vector<int>& right)
{
    std::vector<int>::iterator it_left, it_nums;

    _vNumbers.clear();
    _vNumbers = right;
	for (it_left = left.begin(); it_left < left.end(); it_left++)
		insertNumbersVector(it_left);
    removeExtra();
}

void PmergeMe::display() {
    clock_t start, end;
    double elapsed;
    
    std::cout << "Before: ";
    displayRawNumbers(_vNumbers.begin(), _vNumbers.end());
    std::cout << "After:  ";
    start = clock();
    sortVector();
    end = clock();
    elapsed = (double) ((end - start) * 1000000) / CLOCKS_PER_SEC;
    displayRawNumbers(_vNumbers.begin(), _vNumbers.end());
    std::cout << "Time to process a range of " 
        << _vNumbers.size() 
        << " elements with std::vector<int> : "
        << std::fixed << std::setprecision(5) << elapsed  << " us"
        << std::endl;    
}

void PmergeMe::sortVector() {
    std::vector<std::pair<int, int> > pairs = splitPairsVector();
    std::vector<int> left, right;

    sortSecondElementVector(pairs);
    splitLeftRightVector(pairs, left, right);
    insertionSortVector(left, right);
}

