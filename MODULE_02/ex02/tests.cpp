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

TEST_CASE_FIXTURE(MyFixture, "sum") {
  
    Fixed result = a + b;
    CHECK(result == 4);
}

TEST_CASE_FIXTURE(MyFixture, "sub") {
  
    Fixed result = a - b;
    CHECK(result == 0);
}

TEST_CASE_FIXTURE(MyFixture, "mul") {
  
    Fixed result = a * b;
    CHECK(result == 4);
}
