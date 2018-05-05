// Copyright 2018 Kulikova Svetlana

#include <cmath>

#ifndef MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_H_
#define MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_H_

struct dot {
    double x, y, z;
};

class line_plane_intersection {
 public:
    line_plane_intersection();

    dot PlaneIntersectLine(dot A, dot B, dot C, dot X, dot Y);
    bool GetNotIntersectPlaneLine();

 private:
    bool NotIntersectPlaneLine;

    dot CreateVector(dot A, dot B);
    dot VectorProduct(dot A, dot B);
    double DotProduct(dot A, dot B);
    bool IncorrectLine(dot A, dot B);
    bool IncorrectPlane(dot A, dot B, dot C);
    void Normalize(dot A);
};

#endif  // MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_H_
