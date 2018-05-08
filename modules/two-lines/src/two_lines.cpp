// Copyright 2018 Panov Aleksander

#include "include/two_lines.h"
#include <algorithm>

Point::Point(double _x, double _y) : x(_x), y(_y) {}

inline int orientedArea(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool checkProjection(double startLine1_coord, double endLine1_coord,
    double startLine2_coord, double endLine2_coord) {

    if (startLine1_coord > endLine1_coord)
        std::swap(startLine1_coord, endLine1_coord);
    if (startLine2_coord > endLine2_coord)
        std::swap(startLine2_coord, endLine2_coord);

    return std::max(startLine1_coord, startLine2_coord)
        <= std::min(endLine1_coord, endLine2_coord);
}

bool intersect(Point startLine1, Point endLine1,
    Point startLine2, Point endLine2) {
    return
        checkProjection(startLine1.x, endLine1.x, startLine2.x, endLine2.x) &&
        checkProjection(startLine1.y, endLine1.y, startLine2.y, endLine2.y) &&
        orientedArea(startLine1, endLine1, startLine2) *
        orientedArea(startLine1, endLine1, endLine2) <= 0 &&
        orientedArea(startLine2, endLine2, startLine1) *
        orientedArea(startLine2, endLine2, endLine1) <= 0;
}
