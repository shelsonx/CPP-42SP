#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter: Default constructor called!" << std::endl;
    this->initDataConverters();
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "ScalarConverter: Copy constructor called!" << std::endl;
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { 
    std::cout << "ScalarConverter: Copy assignment constructor called!" << std::endl;
    if (this != &other) {
        this->_charConverter = other._charConverter;
        this->_intConverter = other._intConverter;
        this->_floatConverter = other._floatConverter;
        this->_doubleConverter = other._doubleConverter;
    }
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

void ScalarConverter::initDataConverters() {
    this->_dataConverter.addConverter(&this->_charConverter);
    this->_dataConverter.addConverter(&this->_intConverter);
    this->_dataConverter.addConverter(&this->_floatConverter);
    this->_dataConverter.addConverter(&this->_doubleConverter);
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

void ScalarConverter::convertChar(const std::string& str) {
    this->_charConverter.setStrToChar(
        static_cast<char>(str[0]));
    this->_intConverter.setStrToInt(
        static_cast<int>(this->_charConverter.getStrToChar()));
    this->_floatConverter.setStrToFloat(
        static_cast<float>(this->_charConverter.getStrToChar()));
    this->_doubleConverter.setStrToDouble(
        static_cast<double>(this->_charConverter.getStrToChar()));
    this->_dataConverter.notifyConverters();
}   
