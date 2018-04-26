//
//  fractional_numbers.h
//  fractional_numbers
//
//  Created by Aleksei Khomenko.
//  Copyright © 2018 Aleksei Khomenko. All rights reserved.
//

#ifndef MODULES_FRACTIONAL_NUMBERS_INCLUDE_FRACTIONAL_NUMBERS_H_
#define MODULES_FRACTIONAL_NUMBERS_INCLUDE_FRACTIONAL_NUMBERS_H_

class Rational {
 public:
Rational();
Rational(const int chislit, const int znamenat);
Rational(const Rational& r);

Rational operator + (const Rational& s) const;
Rational operator - (const Rational& s) const;
Rational operator * (const Rational& s) const;
Rational operator / (const Rational& s) const;

Rational& operator= (const Rational& s);
bool operator == (const Rational& r) const;
bool operator != (const Rational& r) const;
int getChislitel() const;
int getZnamenatel() const;
void setChislitel(const int chislitel);
void setZnamenatel(const int znamenatel);

 private:
int Nod(int, int) const;
int a, b;  // a-числитель b-знаменатель
};

#endif  // MODULES_FRACTIONAL_NUMBERS_INCLUDE_FRACTIONAL_NUMBERS_H_
