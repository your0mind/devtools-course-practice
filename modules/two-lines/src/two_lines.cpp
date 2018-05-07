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
    return checkProjection(startLine1.x, endLine1.x, startLine2.x, endLine2.x)
        && checkProjection(startLine1.y, endLine1.y, startLine2.y, endLine2.y)
        && orientedArea(startLine1, endLine1, startLine2) * orientedArea(startLine1, endLine1, endLine2) <= 0
        && orientedArea(startLine2, endLine2, startLine1) * orientedArea(startLine2, endLine2, endLine1) <= 0;
}
