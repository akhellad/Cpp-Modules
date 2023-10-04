#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed x;
    Fixed y;

public:
    Point();
    Point(const float xValue, const float yValue);
    Point(const Point &other);
    ~Point();

    Point &operator=(const Point &other);

    float cross(const Point &other) const;
    Point operator-(const Point &other) const;
    bool operator>=(const Point &other) const;
    bool operator<=(const Point &other) const;
};

#endif // POINT_HPP


