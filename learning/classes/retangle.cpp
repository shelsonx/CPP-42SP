#include <iostream>

class Rectangle {
    int width, height;
    public:
        Rectangle();
        Rectangle(int, int);
        double area(void);
};

Rectangle::Rectangle()
{
    width = 5;
    height = 5;
}

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
    Rectangle rect_a(10, 15);
    Rectangle rect_b;
    std::cout << "Area rect a: " << rect_a.area() << std::endl;
    std::cout << "Area rect b: " << rect_b.area() << std::endl;
}
