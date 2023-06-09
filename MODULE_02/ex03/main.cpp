#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    Point pointInside(2, 2);
    bool resultInside = bsp(a, b, c, pointInside);
    std::cout << "Ponto: " << (resultInside ? "inside" : "outside") << std::endl;

    Point pointOutside(10, 10);
    bool resultOutside = bsp(a, b, c, pointOutside);
    std::cout << "Ponto: " << (resultOutside ? "inside" : "outside") << std::endl;

    return 0;
}
