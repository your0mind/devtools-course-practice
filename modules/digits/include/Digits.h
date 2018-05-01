// Copyright 2018 Kozorez Alexandr

#ifndef DIGITS_CLASS_INCLUDE_H_
#define DIGITS_CLASS_INCLUDE_H_

#include <iostream>

#include <string>

class Digits {
 public:
    Digits();
    ~Digits();
    void InitDigits();
    std::string getLineOfNumeral(int line, int numeral);
    std::string getLineOfNumber(int line, int* arr);
    int* getNumberIntoArray(int n);
 private:
    std::string** digits;
};

#endif // DIGITS_CLASS_INCLUDE_H_
