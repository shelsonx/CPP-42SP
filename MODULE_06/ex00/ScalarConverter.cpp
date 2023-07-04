#include "ScalarConverter.hpp"

CharConverter ScalarConverter::_charConverter;
IntConverter ScalarConverter::_intConverter;
FloatConverter ScalarConverter::_floatConverter;
DoubleConverter ScalarConverter::_doubleConverter;
DataConverter ScalarConverter::_dataConverter;

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
    initDataConverters();
    if (isChar(str))
        convertChar(str);
    else if (isInt(str))
        convertInt(str);
    else if(isFloat(str))
        convertFloat(str);
    else if(isDouble(str))
        convertDouble(str);
}

bool ScalarConverter::isChar(const std::string& str) {
    return (str.length() == 1 && !std::isdigit(str[0]));
}

void ScalarConverter::initDataConverters() {
    _dataConverter.addConverter(&_charConverter);
    _dataConverter.addConverter(&_intConverter);
    _dataConverter.addConverter(&_floatConverter);
    _dataConverter.addConverter(&_doubleConverter);
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
    _charConverter.setStrToChar(static_cast<char>(str[0]));
    _intConverter.setStrToInt(
        static_cast<int>(_charConverter.getStrToChar()));
    _floatConverter.setStrToFloat(
        static_cast<float>(_charConverter.getStrToChar()));
    _doubleConverter.setStrToDouble(
        static_cast<double>(_charConverter.getStrToChar()));
    _dataConverter.notifyConverters();
}

void ScalarConverter::convertInt(const std::string& str) {
    _intConverter.checkConversion(str);
    _intConverter.setStrToInt(static_cast<int>(std::atol(str.c_str())));
    _charConverter.setStrToChar(static_cast<char>(_intConverter.getStrToInt()));
    _floatConverter.setStrToFloat(static_cast<float>(_intConverter.getStrToInt()));
    _doubleConverter.setStrToDouble(static_cast<double>(_intConverter.getStrToInt()));
    _dataConverter.notifyConverters();
}

void ScalarConverter::convertFloat(const std::string& str) {
    _floatConverter.checkConversion(str);
    _floatConverter.setStrToFloat(static_cast<float>(std::atof(str.c_str())));
    _charConverter.setStrToChar(static_cast<char>(_floatConverter.getStrToFloat()));
    _intConverter.setStrToInt(static_cast<int>(_floatConverter.getStrToFloat()));
    _doubleConverter.setStrToDouble(static_cast<double>(_floatConverter.getStrToFloat()));
    _dataConverter.notifyConverters();
}

void ScalarConverter::convertDouble(const std::string& str) {
    _doubleConverter.checkConversion(str);
    _doubleConverter.setStrToDouble(static_cast<double>(std::strtod(str.c_str(), NULL)));
    _charConverter.setStrToChar(static_cast<char>(_doubleConverter.getStrToDouble()));
    _intConverter.setStrToInt(static_cast<int>(_doubleConverter.getStrToDouble()));
    _floatConverter.setStrToFloat(static_cast<float>(_doubleConverter.getStrToDouble()));
    _dataConverter.notifyConverters();
}
