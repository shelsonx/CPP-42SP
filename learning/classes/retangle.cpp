#include <iostream>

class Rectangle {
    int width, height;
    public:
        Rectangle(int, int);
        double area(void);
};

Rectangle::Rectangle (int x, int y)
{
    width = x;
    height = y;
}

double Rectangle::area()
{
    return (width * height);
}

int main (void)
{
    int x, y;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;
    Rectangle rect(x, y);
    std::cout << rect.area() << std::endl;
}
