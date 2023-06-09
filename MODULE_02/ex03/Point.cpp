#include "Point.hpp"

Point::Point() {
    this->x = Fixed(0);
    this->y = Fixed(0);
}

Point::Point(const Point& other) {
    this->x = Fixed(other.getX());
    this->y = Fixed(other.getY());
}

Point& Point::operator=(const Point& other) {
    if (this != &other)
    {
        this->x = Fixed(other.getX());
        this->x = Fixed(other.getY());
    }
    return *this;
}

Point::Point(const float x,const float y) {
    this->x = Fixed(x);
    this->y = Fixed(y);
}

Fixed Point::getX() const {
    return this->x;
}

Fixed Point::getY() const {
    return this->y;
}

Point::~Point() {}
