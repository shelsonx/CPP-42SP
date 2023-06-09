#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Point.hpp"

TEST_CASE("points insides") {
    Point a(2, 2);
    Point b(6, 2);
    Point c(4, 6);

    Point inside1(4, 4);
    Point inside2(3, 3);
    Point inside3(5, 3);

    CHECK(bsp(a, b, c, inside1));
    CHECK(bsp(a, b, c, inside2));
    CHECK(bsp(a, b, c, inside3));
}

TEST_CASE("points outsides") {
    Point a(2, 2);
    Point b(6, 2);
    Point c(4, 6);

    Point outside1(5, 5);
    Point outside2(1, 1);
    Point outside3(7, 5);
  
    CHECK_FALSE(bsp(a, b, c, outside1));
    CHECK_FALSE(bsp(a, b, c, outside2));
    CHECK_FALSE(bsp(a, b, c, outside3));
}
