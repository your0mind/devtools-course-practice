// Copyright 2018 Tipanov Daniil

#pragma once
#include <iostream>
#include <cmath>
#include <vector>

class primeNumbers {
public:
    primeNumbers();
    ~primeNumbers();
    std::vector<int> findPrimeNums(int min, int max);
};
