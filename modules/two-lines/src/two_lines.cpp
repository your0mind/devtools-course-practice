// Copyright 2018 Panov Aleksander

#include "include/two_lines.h"
#include <algorithm>


Point::Point() : x(0), y(0) {}

Point::Point(double _x, double _y) : x(_x), y(_y) {}

inline int orientedArea(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool checkProjection(double x1, double y1, double x2, double y2) {
    if (x1 > y1)  std::swap(x1, y1);
    if (x2 > y2)  std::swap(x2, y2);
    return std::max(x1, x2) <= std::min(y1, y2);
}

bool intersect(Point startLine1, Point endLine1, Point startLine2, Point endLine2) {
    return checkProjection(startLine1.x, b.x, c.x, d.x)
        && checkProjection(startLine1.y, b.y, c.y, d.y)
        && orientedArea(startLine1, b, c) * orientedArea(startLine1, b, d) <= 0
        && orientedArea(c, d, startLine1) * orientedArea(c, d, b) <= 0;
}
