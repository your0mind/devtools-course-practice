// Copyright 2018 Galochkin Boris

#ifndef MODULES_POLYNOMS_INCLUDE_POLYNOM_H_
#define MODULES_POLYNOMS_INCLUDE_POLYNOM_H_

#include <string>
#include <vector>
using std::string;
using std::vector;
class Monom;

class Polynom {
    using monom_vec = vector<Monom>;

 public:
     Polynom();
     explicit Polynom(double coff);
     Polynom(const Polynom& rhs);
     explicit Polynom(const string& str_poly);

     Polynom& operator=(const Polynom& z);

     string toString();

     bool operator==(const Polynom& rhs) const;
     bool operator!=(const Polynom& rhs) const;

     Polynom operator+(const Polynom& rhs);
     Polynom operator-(const Polynom& rhs);
     Polynom operator*(const Polynom& rhs);
     Polynom operator/(const Monom& m);

 private:
     int contains(const monom_vec& vec, const Monom& m) const;

 private:
     monom_vec m_monoms;
};
#endif  // MODULES_POLYNOMS_INCLUDE_POLYNOM_H_
