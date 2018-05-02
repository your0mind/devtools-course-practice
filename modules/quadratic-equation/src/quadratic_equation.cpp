// Copyright 2018 Chvanov Leonid

#include "include/quadratic_equation.h"

#include <math.h>
#include <stdexcept>

QuadraticEquation::QuadraticEquation(const double& _a,
                                     const double& _b,
                                     const double& _c):
                                     a(_a), b(_b), c(_c) {
    if (_a == 0.f)
        throw std::invalid_argument(
              "Quadratic coefficient can not be equal zero");
    discriminant = b*b - 4 *a*c;
    isSolved = false;
}

QuadraticEquation::~QuadraticEquation() { };

std::vector<double> QuadraticEquation::getRoots() {
    if (isSolved) {
        if (this->hasRealRoots())
            return roots;
        else
            throw std::runtime_error(
                  "Quadratic equation has no real roots");
    }
    else {
        this->solve();
        return this->getRoots();
    }
}

void QuadraticEquation::solve() {
    if (!isSolved) {
        if (discriminant > 0) {
            roots.push_back((-b - sqrt(discriminant)) / (2 * a));
            roots.push_back((-b + sqrt(discriminant)) / (2 * a));
        }
        else if (discriminant == 0) {
            roots.push_back((-b - sqrt(discriminant)) / (2 * a));
        }
    }
    isSolved = true;
}

bool QuadraticEquation::hasRealRoots() {
    return (discriminant >= 0);
}