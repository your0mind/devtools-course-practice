// Copyright 2018 Kulikova Svetlana

#include <cmath>

#ifndef MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_H_
#define MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_H_

struct xyz {
    double x, y, z;
};

class line_plane_intersection {
 public:
    line_plane_intersection();

    xyz PlaneIntersectLine(xyz A, xyz B, xyz C, xyz X, xyz Y);
    bool GetNotIntersectPlaneLine();

 private:
    bool NotIntersectPlaneLine;

    xyz CreateVector(xyz A, xyz B);
    xyz VectorProduct(xyz A, xyz B);
    double DotProduct(xyz A, xyz B);
    bool IncorrectLine(xyz A, xyz B);
    bool IncorrectPlane(xyz A, xyz B, xyz C);
    void Normalize(xyz A);
};

#endif  // MODULES_LINE_PLANE_INTERSECTION_INCLUDE_LINE_PLANE_INTERSECTION_H_
