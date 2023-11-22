#include "../includes/bsp.hpp"

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
    Point ab = b - a;
    Point bc = c - b;
    Point ca = a - c;

    Point ap = point - a;
    Point bp = point - b;
    Point cp = point - c;

    float cross1 = ab.cross(ap);
    float cross2 = bc.cross(bp);
    float cross3 = ca.cross(cp);


    if ((cross1 >= 0 && cross2 >= 0 && cross3 >= 0) ||
        (cross1 <= 0 && cross2 <= 0 && cross3 <= 0))
        return true;

    return false;
}