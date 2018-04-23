//
//  fractional_numbers.hpp
//  fractional_numbers
//
//  Created by Alexey Khomenko on 23.04.18.
//  Copyright © 2018 Alexey Khomenko. All rights reserved.
//

#ifndef fractional_numbers_h
#define fractional_numbers_h

#include <stdio.h>
class Rational
{
    
public:
    
    Rational ();
    Rational (const int chislit, const int znamenat);
    Rational (const Rational& r);
    Rational operator+ (const Rational& s) const;
    Rational operator- (const Rational& s) const;
    Rational operator* (const Rational& s) const;
    Rational operator/ (const Rational& s) const;
    
    Rational& operator= (const Rational& s);
    
    bool operator == (const Rational& r) const;
    
    int getChislitel() const;
    int getZnamenatel() const;
    void setChislitel(const int chislitel);
    void setZnamenatel(const int znamenatel);
    
private:
    int Nod (int, int) const;
    int a,b; //a-числитель b-знаменатель//
};

#endif /* fractional_numbers_h */
