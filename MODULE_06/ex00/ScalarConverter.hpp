#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        static bool isChar(const std::string& str);
        static bool isInt(const std::string& str);
        static bool isDouble(const std::string& str);
        static bool isFloat(const std::string& str);

        static void convert(const std::string& str);
    private:
};

#endif