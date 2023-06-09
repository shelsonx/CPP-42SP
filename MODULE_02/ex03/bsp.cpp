#include "Point.hpp"

Fixed getCrossProduct (const Point p1, const Point p2, const Point p3)
{
    return (p1.getY() - p2.getY()) - (p3.getY() - p2.getY());
}

Fixed getHorzDist (const Point p1, const Point p2)
{
    return (p1.getX() - p2.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {

    Fixed r1 = getHorzDist(b, a) * getCrossProduct(point, a, b) * getHorzDist(point, a);
    Fixed r2 = getHorzDist(c, b) * getCrossProduct(point, c, b) * getHorzDist(point, b);
    Fixed r3 = getHorzDist(a, c) * getCrossProduct(point, c, a) * getHorzDist(point, c);

    return (r1 >= 0 && r2 >= 0 && r3 >= 0);
}
