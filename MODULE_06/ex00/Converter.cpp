#include "Converter.hpp"

Converter::Converter() {
    this->isConvertible = true;
}

void CharConverter::update() {
    if (std::isprint(_strToChar))
        std::cout << "char: " << this->_strToChar << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void CharConverter::checkConversion(const std::string& str) {
    (void) str;
    return;
}

char CharConverter::getStrToChar() const {
    return this->_strToChar;
}

void CharConverter::setStrToChar(char c) {
    this->_strToChar = c;
}

void IntConverter::update() {
    if (this->isConvertible)
        std::cout << "int: " << this->_strToInt << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
}

void IntConverter::checkConversion(const std::string& str) {
    
    long int value = std::atol(str.c_str());

    if (value > INT_MAX || value < INT_MIN)
        this->isConvertible = false;
}

int IntConverter::getStrToInt() const {
    return this->_strToInt;
}

void IntConverter::setStrToInt(int i) {
    this->_strToInt = i;
}

void FloatConverter::update() {
    if (this->isConvertible) {
        std::cout << "float: " << this->_strToFloat 
        << (hasDecimal(_strToFloat) ? ".0f": "f") << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;
}

void FloatConverter::checkConversion(const std::string& str) {
    double value = std::atof(str.c_str());
    if (value > FLT_MAX || value < FLT_MIN)
        this->isConvertible = false;
}

bool FloatConverter::hasDecimal(float value) {
    float intPart;
    float fracPart = std::modf(value, &intPart);
    return fracPart == 0.0f;
}

float FloatConverter::getStrToFloat() const {
    return this->_strToFloat;
}

void FloatConverter::setStrToFloat(float f) {
    this->_strToFloat = f;
}

void DoubleConverter::update() {
    if (this->isConvertible) {
        std::cout << "double: " << this->_strToDouble 
        << (hasDecimal(_strToDouble) ? ".0": "") << std::endl;
    }
    else
        std::cout << "double: impossible" << std::endl;
}

void DoubleConverter::checkConversion(const std::string& str) {
    long double value = std::strtod(str.c_str(), NULL);
    if (value > DBL_MAX || value < DBL_MIN)
        this->isConvertible = false;
}

bool DoubleConverter::hasDecimal(double value) {
    double intPart;
    double fracPart = std::modf(value, &intPart);
    return fracPart == 0.0;
}

double DoubleConverter::getStrToDouble() const {
    return this->_strToDouble;
}

void DoubleConverter::setStrToDouble(double d) {
    this->_strToDouble = d;
}
