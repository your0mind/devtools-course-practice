// Copyright 2018 Panov Aleksander

#include "include/two_lines.h"
#include <algorithm>


Point::Point() : x(0), y(0) {}

Point::Point(double _x, double _y) : x(_x), y(_y) {}

inline int orientedArea(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool checkProjection(double a, double b, double c, double d)
{
    if (a > b)  std::swap(a, b);
    if (c > d)  std::swap(c, d);
    return std::max(a, c) <= std::min(b, d);
}

bool intersect(Point a, Point b, Point c, Point d) {
    return checkProjection(a.x, b.x, c.x, d.x)
        && checkProjection(a.y, b.y, c.y, d.y)
        && orientedArea(a, b, c) * orientedArea(a, b, d) <= 0
        && orientedArea(c, d, a) * orientedArea(c, d, b) <= 0;
}
