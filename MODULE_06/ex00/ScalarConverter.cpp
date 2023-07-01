#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter: Default constructor called!" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "ScalarConverter: Copy constructor called!" << std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { 
    std::cout << "ScalarConverter: Copy assignment constructor called!" << std::endl;
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter: Default destructor called!" << std::endl;
}

void ScalarConverter::convert(const std::string& str) {
    std::cout << (isInt(str) ? "True" : "False") << std::endl;
}

bool ScalarConverter::isChar(const std::string& str) {
    return (str.length() == 1 && !std::isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string& str) {
    size_t count = 0;

    if (str.empty())
        return false;
    while(str[count] == '+' || str[count] == '-')
        count++;
    while (count < str.length() && std::isdigit(str[count]))
        count++;
    return (count == str.length());
}

bool ScalarConverter::isDouble(const std::string& str) {
    bool isDecimal = false;
    bool isDigit = false;
    size_t count = 0;

    if (str.empty())
        return false;
    while(str[count] == '+' || str[count] == '-')
        count++;
    while (count < str.length()) {
        if (std::isdigit(str[count]))
            isDigit = true;
        else if (str[count] == '.' && !isDecimal)
            isDecimal = true;
        else
            return false;
        count++;
    }
    return isDigit && isDecimal;
}

bool ScalarConverter::isFloat(const std::string& str) {
    size_t size = str.length() -1;
    return isDouble(str.substr(0, size)) && str[size] == 'f';
}
