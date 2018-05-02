// Copyright 2018 Panov Aleksander

#ifndef MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
#define MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
class Line
{
public:
    Line();
    Line(const double _x, const double _y);
    Line(const Line &l);

    Line& operator=(const Line &l);

    double getX() const;
    double getY() const;
    void setX(const double _x);
    void setY(const double _y);

    bool isIntersection(const Line &l) const;

    bool operator == (const Line& l) const;
    bool operator != (const Line& l) const;
private:
    double x;
    double y;
    bool equalsZero() const;
};
#endif  // MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
