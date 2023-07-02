#ifndef SCALARCONVERTER_HPP

#define SCALARCONVERTER_HPP

#include <iostream>
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

        void convertChar(const std::string& str);
        void initDataConverters();

        static void convert(const std::string& str);

    private:
        DataConverter _dataConverter;
        CharConverter _charConverter;
        IntConverter _intConverter;
        FloatConverter _floatConverter;
        DoubleConverter _doubleConverter;

};

#endif