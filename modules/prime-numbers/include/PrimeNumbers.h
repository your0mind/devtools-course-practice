// Copyright 2018 Tipanov Daniil

#ifndef MODULES_PRIME_NUMBERS_INCLUDE_PRIMENUMBERS_H_
#define MODULES_PRIME_NUMBERS_INCLUDE_PRIMENUMBERS_H_

#include <iostream>
#include <cmath>
#include <vector>

class primeNumbers {
 public:
    primeNumbers();
    ~primeNumbers();
    std::vector<int> findPrimeNums(int min, int max);
};

#endif // MODULES_PRIME_NUMBERS_INCLUDE_PRIMENUMBERS_H_
