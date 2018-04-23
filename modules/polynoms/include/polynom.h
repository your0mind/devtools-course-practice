// Copyright 2018 Galochkin Boris
#ifndef MODULES_POLYNOMS_INCLUDE_POLYNOM_H_
#define MODULES_POLYNOMS_INCLUDE_POLYNOM_H_
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "include/monom.h"

class Polynom {
 public:
     Polynom();
     explicit Polynom(double coff);
     Polynom(const Polynom& rhs);
     explicit Polynom(const std::string& str_poly);

     Polynom& operator=(const Polynom& z);

     std::string toString();

     bool operator==(const Polynom& rhs) const;
     bool operator!=(const Polynom& rhs) const;

     Polynom operator+(const Polynom& rhs);
     Polynom operator-(const Polynom& rhs);
     Polynom operator*(const Polynom& rhs);
     Polynom operator/(const Monom& m);

 private:
     int contains(const std::vector<Monom>& vec, const Monom& m) const;

 private:
     std::vector<Monom> m_monoms;
};
#endif  // MODULES_POLYNOMS_INCLUDE_POLYNOM_H_
