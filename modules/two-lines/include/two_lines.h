// Copyright 2018 Panov Aleksandr

#ifndef MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
#define MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
class Line
{
public:
    Line();
    Line(double x, double y);
    Line(const Line &l);

    Line& operator=(const Line &l);

    double getX() const;
    double getY() const;
    void setX();
    void setY();

    bool isIntersection(const Line &l) const;
private:
    double x;
    double y;
};
#endif  // MODULES_TWO_LINES_INCLUDE_TWO_LINES_H_
