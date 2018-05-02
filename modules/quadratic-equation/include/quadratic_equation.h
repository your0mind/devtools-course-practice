// Copyright 2018 Chvanov Leonid

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_

#include <vector>

class QuadraticEquation {
 public:
     QuadraticEquation(const double& _a, 
                       const double& _b, 
                       const double& _c);
     ~QuadraticEquation();
     
     std::vector<double> getRoots();

 private:
     double a, b, c;//coefficients
     double discriminant;
     std::vector<double> roots;

     bool isSolved;

     bool hasRealRoots();
     void solve();
};

#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
