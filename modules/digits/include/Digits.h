// Copyright 2018 Kozorez Alexandr

#ifndef MODULES_DIGITS_INCLUDE_DIGITS_H_
#define MODULES_DIGITS_INCLUDE_DIGITS_H_

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

#endif  // MODULES_DIGITS_INCLUDE_DIGITS_H_
