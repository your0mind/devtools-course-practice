// Copyright 2018 Galochkin Boris

#ifndef MODULES_POLYNOMS_INCLUDE_MONOM_H_
#define MODULES_POLYNOMS_INCLUDE_MONOM_H_

#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
using POW_TYPE = double;
using VAR_NAME = char;

class Monom {
 public:
    explicit Monom(double c = 1.0);
    Monom(const Monom& rhs);
    explicit Monom(const std::string& str_monom);

    Monom& operator=(const Monom& z);

    std::string toString();

    bool operator==(const Monom& rhs) const;
    bool operator!=(const Monom& rhs) const;

    Monom operator+(const Monom& rhs);
    Monom operator-(const Monom& rhs);
    Monom operator*(const Monom& rhs);
    Monom operator/(const Monom& rhs);

 private:
    std::string str_emplace_spaces(const std::string& s);
    void str_parse_symbols(const std::string& s);
    bool equals_variabels(const Monom& r) const;

 private:
    std::map<VAR_NAME, POW_TYPE> m_variabels;
    double m_coff;

    std::set<char> ok_symbols = { '^', '.', ',', '+', '-' };

    friend class Polynom;
};
#endif  // MODULES_POLYNOMS_INCLUDE_MONOM_H_
