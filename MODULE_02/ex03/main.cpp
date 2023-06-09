#include "Point.hpp"

int main() {
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);

    Point point(2, 2);
    std::cout << "Ponto: " 
        << (bsp(a, b, c, point) ? "inside" : "outside") 
        << std::endl;

    point = Point(10, 10);
    std::cout << "Ponto: " 
        << (bsp(a, b, c, point) ? "inside" : "outside") 
        << std::endl;
    return 0;
}
