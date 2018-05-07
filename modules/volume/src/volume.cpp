// Copyright 2018 Shurygin Dmitriy

#include "include/volume.h"

#define _USE_MATH_DEFINES
#include <math.h>

Sphere::Sphere() : R(0) {}

Sphere::Sphere(const double _R) : R(_R) {}

Sphere::Sphere(const Sphere& sphere) : R(sphere.getR()) {}

double Sphere::getR() const {
    return R;
}

void Sphere::setR(const double _R) {
    R=_R;
}

double Sphere::Volume() {
    return M_PI * R * R * R;
}


Cube::Cube() : A(0) {}

Cube::Cube(const double _A) : A(_A) {}

Cube::Cube(const Cube& Cube) : A(Cube.getA()) {}

double Cube::getA() const {
    return A;
}

void Cube::setA(const double _A) {
    A = _A;
}


double Cube::Volume() {
    return A * A * A;
}

Cylinder::Cylinder() : R(0), h(0) {}

Cylinder::Cylinder(const double _R, const double _h) : R(_R), h(_h) {}

Cylinder::Cylinder(const Cylinder& cylinder)
         : R(cylinder.getR()), h(cylinder.geth()) {}

double Cylinder::getR() const {
    return R;
}

void Cylinder::setR(const double _R) {
    R = _R;
}

void Cylinder::seth(const double _h) {
    h = _h;
}


double Cylinder::geth() const {
    return h;
}

double Cylinder::Volume() {
    return M_PI * R * R * h;
}
