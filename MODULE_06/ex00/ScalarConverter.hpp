#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include "Converter.hpp"
#include "DataConverter.hpp"

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

        static void convertChar(const std::string& str);
        static void convertInt(const std::string& str);
        static void initDataConverters();

        static void convert(const std::string& str);

    private:
        static DataConverter _dataConverter;
        static CharConverter _charConverter;
        static IntConverter _intConverter;
        static FloatConverter _floatConverter;
        static DoubleConverter _doubleConverter;

};

#endif