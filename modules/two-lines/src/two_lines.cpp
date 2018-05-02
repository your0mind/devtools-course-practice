// Copyright 2018 Panov Aleksander

#include "include/two_lines.h"
#include <limits>

const double eps = std::numeric_limits<double>::epsilon();

Line::Line():x(0), y(0){}

Line::Line(const double _x, const double _y):x(_x), y(_y){}

Line::Line(const Line & l):x(l.x), y(l.y){}

Line& Line::operator=(const Line & l)
{
    x = l.x;
    y = l.y;
    return *this;
}

double Line::getX() const
{
    return x;
}

double Line::getY() const
{
    return y;
}

void Line::setX(const double _x)
{
    x = _x;
}

void Line::setY(const double _y)
{
    y = _y;
}

bool Line::isIntersection(const Line & l) const
{
    return false;
}

bool Line::equalsZero() const 
{
    return x < eps && x > -eps &&
        y < eps && y > -eps;
}

bool Line::operator==(const Line & l) const
{
    return Line(x-l.x, y-l.y).equalsZero();
}

bool Line::operator!=(const Line & l) const
{
    return !(*this == l);
}
