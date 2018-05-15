// Copyright 2018 Panov Aleksander

#include <algorithm>
#include <limits>
#include "include/two_lines.h"

using std::swap;
using std::max;
using std::min;

const double eps = std::numeric_limits<double>::epsilon();

bool equalsZero(double x) {
    return std::abs(x) < eps;
}

Point::Point() : x(0), y(0) {}

Point::Point(double _x, double _y) : x(_x), y(_y) {}

bool Point::operator==(const Point & point) const {
    return (equalsZero(x - point.x) && equalsZero(y - point.y));
}

bool Point::operator!=(const Point & point) const {
    return !(*this == point);
}

inline double orientedArea(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool checkProjection(double startLine1_coord, double endLine1_coord,
    double startLine2_coord, double endLine2_coord) {
    if (startLine1_coord > endLine1_coord)
        swap(startLine1_coord, endLine1_coord);
    if (startLine2_coord > endLine2_coord)
        swap(startLine2_coord, endLine2_coord);
    return (max(startLine1_coord, startLine2_coord)
        <= min(endLine1_coord, endLine2_coord));
}

bool intersect(Point startLine1, Point endLine1,
    Point startLine2, Point endLine2) {
    bool isX, isY;
    isX = checkProjection(startLine1.x, endLine1.x, startLine2.x, endLine2.x);
    isY = checkProjection(startLine1.y, endLine1.y, startLine2.y, endLine2.y);
    double orientedArea1, orientedArea2, orientedArea3, orientedArea4;
    orientedArea1 = orientedArea(startLine1, endLine1, startLine2);
    orientedArea2 = orientedArea(startLine1, endLine1, endLine2);
    orientedArea3 = orientedArea(startLine2, endLine2, startLine1);
    orientedArea4 = orientedArea(startLine2, endLine2, endLine1);
    return
        (isX && isY
         && orientedArea1 * orientedArea2 <= 0
         && orientedArea3 * orientedArea4 <= 0);
}

LineSegment::LineSegment(): point1(), point2() {}

LineSegment::LineSegment(Point _point1, Point _point2):
    point1(_point1), point2(_point2) {}

LineSegment::LineSegment(const LineSegment & line):
    point1(line.point1), point2(line.point2) {}

Point LineSegment::getPoint1() const {
    return point1;
}

Point LineSegment::getPoint2() const {
    return point2;
}

bool LineSegment::intersect(const LineSegment & line) const {
    bool isX, isY;
    isX = checkProjection(point1.x, point2.x, line.point1.x, line.point2.x);
    isY = checkProjection(point1.y, point2.y, line.point1.y, line.point2.y);
    double orientedArea1, orientedArea2, orientedArea3, orientedArea4;
    orientedArea1 = orientedArea(point1, point2, line.point1);
    orientedArea2 = orientedArea(point1, point2, line.point2);
    orientedArea3 = orientedArea(line.point1, line.point2, point1);
    orientedArea4 = orientedArea(line.point1, line.point2, point2);
    return
        (isX && isY
            && orientedArea1 * orientedArea2 <= 0
            && orientedArea3 * orientedArea4 <= 0);
}

bool LineSegment::operator==(const LineSegment & line) const {
    return (point1 == line.point1 && point2 == line.point2 ||
        point2 == line.point1 && point1 == line.point2);
}

bool LineSegment::operator!=(const LineSegment & line) const {
    return !(*this == line);
}
