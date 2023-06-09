#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    public:
        Point(void);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();
        Point(const float x,const float y);

        Fixed getX() const;
        Fixed getY() const;
    private:
        Fixed x;
        Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif