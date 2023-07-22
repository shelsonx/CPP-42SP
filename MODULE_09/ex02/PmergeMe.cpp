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

void PmergeMe::removeExtraVector() {
    if (_vNumbers[0] < 0)
        _vNumbers.erase(_vNumbers.begin());  
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

void PmergeMe::insertionSortVector(std::vector<int>& left, std::vector<int>& right)
{
    std::vector<int>::iterator it_left, it_nums;

    _vNumbers.clear();
    _vNumbers = right;
	for (it_left = left.begin(); it_left < left.end(); it_left++)
		insertNumbersVector(it_left);
    removeExtraVector();
}

void PmergeMe::sortVector() {
    std::vector<std::pair<int, int> > pairs = splitPairsVector();
    std::vector<int> left, right;

    sortSecondElementVector(pairs);
    splitLeftRightVector(pairs, left, right);
    insertionSortVector(left, right);
}

std::deque<std::pair<int, int> > PmergeMe::splitPairsDeque() {
    std::deque<std::pair<int, int> > pairs;

    for (size_t i = 0; i + 1 < _dNumbers.size(); i += 2) {
        if (_dNumbers[i] > _dNumbers[i + 1]) {
            pairs.push_back(std::make_pair(_dNumbers[i + 1], _dNumbers[i]));
        } else {
            pairs.push_back(std::make_pair(_dNumbers[i], _dNumbers[i + 1]));
        }
    }
    if (_dNumbers.size() % 2 != 0) {
        pairs.push_back(std::make_pair(_dNumbers.back(), -1));
    }
    return pairs;
}

void PmergeMe::sortSecondElementDeque(std::deque<std::pair<int, int> >& pairs) {
    size_t size = pairs.size();

    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (pairs[j].second > pairs[j + 1].second) {
                std::swap(pairs[j], pairs[j + 1]);
            }
        }
    }
}

void PmergeMe::splitLeftRightDeque(const std::deque<std::pair<int, int> >& pairs, 
            std::deque<int>& left, 
            std::deque<int>& right) {
    for (size_t i = 0; i < pairs.size(); ++i) {
        left.push_back(pairs[i].first);
        right.push_back(pairs[i].second);
    }
}

void PmergeMe::insertNumbersDeque(std::deque<int>::iterator it_left) {
    std::deque<int>::iterator it_nums;

    for (it_nums = _dNumbers.begin(); it_nums <= _dNumbers.end(); it_nums++)
    {
        if (*it_left <= *it_nums)
        {
            _dNumbers.insert(it_nums, *it_left);
            break ;
        }
        else if (it_nums == _dNumbers.end()) {
            _dNumbers.push_back(*it_left);
            break;
        }
    }
}

void PmergeMe::removeExtraDeque() {
    if (_dNumbers[0] < 0)
        _dNumbers.erase(_dNumbers.begin()); 
}

void PmergeMe::insertionSortDeque(std::deque<int>& left, std::deque<int>& right) {
    std::deque<int>::iterator it_left;

    _dNumbers.clear();
    _dNumbers = right;
	for (it_left = left.begin(); it_left < left.end(); it_left++)
		insertNumbersDeque(it_left);
    removeExtraDeque(); 
}

void PmergeMe::sortDeque() {
    std::deque<std::pair<int, int> > pairs = splitPairsDeque();
    std::deque<int> left, right;

    sortSecondElementDeque(pairs);
    splitLeftRightDeque(pairs, left, right);
    insertionSortDeque(left, right);
}

void PmergeMe::display() {
    clock_t startVector, startDeque, endVector, endDeque;
    double elapsedVector, elapsedDeque;
    
    std::cout << "Before: ";
    displayRawNumbers(_vNumbers.begin(), _vNumbers.end());
    std::cout << "After:  ";
    
    startVector = clock();
    sortVector();
    endVector = clock();
    elapsedVector = (double) ((endVector - startVector) * 1000000) / CLOCKS_PER_SEC;
    
    startDeque = clock();
    sortDeque();
    endDeque = clock();
    elapsedDeque = (double) ((endDeque - startDeque) * 1000000) / CLOCKS_PER_SEC;

    displayRawNumbers(_vNumbers.begin(), _vNumbers.end());
    std::cout << "Time to process a range of " 
        << _vNumbers.size() 
        << " elements with std::vector<int> : "
        << std::fixed << std::setprecision(5) << elapsedVector  << " us"
        << std::endl; 

     std::cout << "Time to process a range of " 
        << _dNumbers.size() 
        << " elements with std::deque<int> : "
        << std::fixed << std::setprecision(5) << elapsedDeque  << " us"
        << std::endl;    
}

void PmergeMe::sort() {
    display();
}
