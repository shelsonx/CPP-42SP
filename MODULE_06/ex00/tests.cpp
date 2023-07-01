#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "ScalarConverter.hpp"

TEST_CASE("isChar") {
    //Check Numbers
    CHECK_FALSE(ScalarConverter::isChar("1"));
    CHECK_FALSE(ScalarConverter::isChar("4"));

    //Check lenth > 1
    CHECK_FALSE(ScalarConverter::isChar("42"));
    CHECK_FALSE(ScalarConverter::isChar("SP"));
    CHECK_FALSE(ScalarConverter::isChar("Engineer"));
    CHECK_FALSE(ScalarConverter::isChar("%^@"));

    //Other tests
    CHECK_FALSE(ScalarConverter::isChar(""));

    //Check True
    CHECK(ScalarConverter::isChar("c"));
    CHECK(ScalarConverter::isChar("&"));
    CHECK(ScalarConverter::isChar("#"));
    CHECK(ScalarConverter::isChar("C"));
    CHECK(ScalarConverter::isChar(" "));
    CHECK(ScalarConverter::isChar("\t"));
    CHECK(ScalarConverter::isChar("\n"));
}

TEST_CASE("isInt") {

    //Checks False
    CHECK_FALSE(ScalarConverter::isInt("c"));
    CHECK_FALSE(ScalarConverter::isInt("C"));
    CHECK_FALSE(ScalarConverter::isInt("42 SP"));
    CHECK_FALSE(ScalarConverter::isInt("10.4"));
    CHECK_FALSE(ScalarConverter::isInt("5.4f"));

    CHECK_FALSE(ScalarConverter::isInt(""));
    CHECK_FALSE(ScalarConverter::isInt(" "));

    //Checks True
    CHECK(ScalarConverter::isInt("1"));
    CHECK(ScalarConverter::isInt("42"));
    CHECK(ScalarConverter::isInt("2023"));
    CHECK(ScalarConverter::isInt("-43"));
    CHECK(ScalarConverter::isInt("+7"));
    CHECK(ScalarConverter::isInt("++7"));
    CHECK(ScalarConverter::isInt("+-7"));
    CHECK(ScalarConverter::isInt("---++--+39"));
}

TEST_CASE("isDouble") {
    //Checks False
    CHECK_FALSE(ScalarConverter::isDouble("c"));
    CHECK_FALSE(ScalarConverter::isDouble("C"));
    CHECK_FALSE(ScalarConverter::isDouble("42 SP"));
    CHECK_FALSE(ScalarConverter::isDouble("5"));

    CHECK_FALSE(ScalarConverter::isDouble(""));
    CHECK_FALSE(ScalarConverter::isDouble(" "));

    //Checks True
    CHECK(ScalarConverter::isDouble("1.0"));
    CHECK(ScalarConverter::isDouble("42.0"));
    CHECK(ScalarConverter::isDouble("20.23"));
    
    CHECK(ScalarConverter::isDouble("-43.5"));
    CHECK(ScalarConverter::isDouble("+7.8"));
    CHECK(ScalarConverter::isDouble("++7.9"));
    CHECK(ScalarConverter::isDouble("+-7.10"));
    CHECK(ScalarConverter::isDouble("---++--+39.1"));
}

TEST_CASE("isFloat") {
    //Checks False
    CHECK_FALSE(ScalarConverter::isFloat("c"));
    CHECK_FALSE(ScalarConverter::isFloat("C"));
    CHECK_FALSE(ScalarConverter::isFloat("42 SP"));
    CHECK_FALSE(ScalarConverter::isFloat("5"));

    CHECK_FALSE(ScalarConverter::isFloat(""));
    CHECK_FALSE(ScalarConverter::isFloat(" "));

    //Checks True
    CHECK(ScalarConverter::isFloat("1.0f"));
    CHECK(ScalarConverter::isFloat("42.0f"));
    CHECK(ScalarConverter::isFloat("20.23f"));
    
    CHECK(ScalarConverter::isFloat("-43.5f"));
    CHECK(ScalarConverter::isFloat("+7.8f"));
    CHECK(ScalarConverter::isFloat("++7.9f"));
    CHECK(ScalarConverter::isFloat("+-7.10f"));
    CHECK(ScalarConverter::isFloat("---++--+39.1f"));
}