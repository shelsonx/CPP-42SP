#include "Point.hpp"

int main() {
    Point a(2, 2);
    Point b(6, 2);
    Point c(4, 6);

    Point inside1(4, 4);
    Point outside1(5, 5);

    std::cout << "Point (4, 4): " << (bsp(a, b, c, inside1) ? "Inside" : "Outside") << std::endl;
    std::cout << "Point (5, 5): " << (bsp(a, b, c, outside1) ? "Inside" : "Outside") << std::endl;

    return 0;
}
