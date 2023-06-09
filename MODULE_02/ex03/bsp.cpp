#include "Point.hpp"

Fixed getHorzDist (const Point p1, const Point p2)
{
    return (p1.getX() - p2.getX());
}

Fixed getVertDist (const Point p1, const Point p2)
{
    return (p1.getY() - p2.getY());
}

Fixed CalcCrossProd(const Point p1, const Point p2, const Point p3) {
    return 
        getHorzDist(p1, p2) * getVertDist(p3, p2) - 
        getVertDist(p1, p2) * getHorzDist(p3, p2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed r1 = CalcCrossProd(b, a, point);
    Fixed r2 = CalcCrossProd(c, b, point);
    Fixed r3 = CalcCrossProd(a, c, point);

    return (r1 >= 0 && r2 >= 0 && r3 >= 0);
}
