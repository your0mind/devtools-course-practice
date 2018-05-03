// Copyright 2018 Panov Aleksander

#ifndef MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
#define MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_

struct Point
{
    double x;
    double y;
    Point():x(0.0), y(0.0) {};
    Point(double _x, double _y) :x(_x), y(_y) {};
};

bool intersect(Point a, Point b, Point c, Point d);

#endif  // MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
