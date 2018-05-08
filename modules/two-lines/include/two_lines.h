// Copyright 2018 Panov Aleksander

#ifndef MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
#define MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_

struct Point {
    double x;
    double y;
    Point(double _x, double _y);
};

bool intersect(Point startLine1, Point endLine1,
    Point startLine2, Point endLine2);

#endif  // MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
