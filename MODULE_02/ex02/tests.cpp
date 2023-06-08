#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Fixed.hpp"

struct MyFixture {
    Fixed a;
    Fixed b;

    MyFixture() {
        a = 2;
        b = 2;
    }
};

TEST_CASE_FIXTURE(MyFixture, "arithmetic operators") {
  
    Fixed sum = a + b;
    Fixed sub = a - b;
    Fixed mul = a * b;
    Fixed div = a / b;

    CHECK(sum == 4);
    CHECK(sub == 0);
    CHECK(mul == 4);
    CHECK(div == 1);
}

TEST_CASE_FIXTURE(MyFixture, "increments and decrements") {
    a = 3;
    b = 3;
    CHECK(++a == ++b);
    a++;
    b++;
    CHECK(a == b);
    CHECK(--a == --b);
    a--;
    b--;
    CHECK(a == b);
}

TEST_CASE_FIXTURE(MyFixture, "comparison operators") {
    a = 2;
    b = 1;
    std::string result1 = a > b ? "true" : "false";
    std::string result2 = b < a ? "true" : "false";
    b = 2;
    std::string result3 = b >= a ? "true" : "false";
    std::string result4 = b <= a ? "true" : "false";
    std::string result5 = b == a ? "true" : "false";
    std::string result6 = b != a ? "true" : "false";
    CHECK(result1 == "true");
    CHECK(result2 == "true");
    CHECK(result3 == "true");
    CHECK(result4 == "true");
    CHECK(result5 == "true");
    CHECK(result6 == "false");
}

TEST_CASE_FIXTURE(MyFixture, "min and max") {
    Fixed const c = 2;
    Fixed const d = 3;

    Fixed const min = Fixed::min( c, d );
    CHECK_EQ(min.toFloat(), 2.0);

    Fixed const max = Fixed::max( c, d );
    CHECK_EQ(max.toFloat(), 3.0);
}
