#include "Converter.hpp"

void CharConverter::update() {
    std::cout << "char: " << this->_strToChar << std::endl;
}

char CharConverter::getStrToChar() const {
    return this->_strToChar;
}

void CharConverter::setStrToChar(char c) {
    this->_strToChar = c;
}

void IntConverter::update() {
    std::cout << "int: " << this->_strToInt << std::endl;
}

int IntConverter::getStrToInt() const {
    return this->_strToInt;
}

void IntConverter::setStrToInt(int i) {
    this->_strToInt = i;
}

void FloatConverter::update() {
    std::cout << "float: " << this->_strToFloat << ".0f" << std::endl;
}

float FloatConverter::getStrToFloat() const {
    return this->_strToFloat;
}

void FloatConverter::setStrToFloat(float f) {
    this->_strToFloat = f;
}

void DoubleConverter::update() {
    std::cout << "double: " << this->_strToDouble << ".0" << std::endl;
}

double DoubleConverter::getStrToDouble() const {
    return this->_strToDouble;
}

void DoubleConverter::setStrToDouble(double d) {
    this->_strToDouble = d;
}
