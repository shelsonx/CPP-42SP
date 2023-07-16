#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

int RPN::stoi( std::string& s ) {
    int i;

    std::istringstream(s) >> i;
    if (i == 0 && s.compare("0") != 0)
		return -1;
	return i;
}

void RPN::checkLessTen(std::string inputs) {
    std::istringstream iss(inputs);
    std::string token;

    while (iss >> token) {
        if (std::isdigit(token[0])) {
            if (stoi(token) >= 10)
                throw std::out_of_range("Error: Number too large.");
        }
    }
}

void RPN::checkValidChar(char& c) {
    std::string validInputs = "+-*/1234567890 ";

    if (validInputs.find(c) == std::string::npos)
        throw std::invalid_argument("Error: Invalid Character");
}

int RPN::applyOperation(char& op) {
    int first, second, result;
    
    first = this->_stack.top();
    this->_stack.pop();
    second = this->_stack.top();
    this->_stack.pop();
    
    if (op == '+')
        result = second + first;
    else if (op == '-')
        result = second - first;
    else if (op == '*')
        result = second * first;
    else if (op == '/') {
        if (first == 0)
            throw std::runtime_error("Error: Division by zero."); 
        result = second / first;
    }
    return result;
}

void RPN::skipSpace(std::string::iterator& it) {
    if (*it == ' ')
        it++;
}

int RPN::convertCharToInt(char& c) {
    return (c - '0');
}

void RPN::execute(std::string& inputs) {
    std::string::iterator it;

    if (inputs.empty())
        return;
    checkLessTen(inputs);
    for (it = inputs.begin(); it != inputs.end(); ++it) {
        checkValidChar(*it);
        skipSpace(it);
        if (std::isdigit(*it))
            this->_stack.push(convertCharToInt(*it));
        else {
            if (this->_stack.size() >= 2)
                this->_stack.push(applyOperation(*it));
            else
                throw std::runtime_error("Error: Invalid Input.");
        }
    }
    std::cout << this->_stack.top() << std::endl;
}
