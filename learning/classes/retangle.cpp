#include <iostream>

class Rectangle {
    int x, y;
    public:
        void set_values(int, int);
        double area(void);
};

void Rectangle::set_values(int a, int b)
{
    x = a;
    y = b;
}

double Rectangle::area(void)
{
    return (x * y);
}

int main (void)
{
    Rectangle rect;
    int x, y;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;
    rect.set_values(x, y);
    std::cout << rect.area() << std::endl;
}
