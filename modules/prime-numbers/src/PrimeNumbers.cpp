// Copyright 2018 Tipanov Daniil

#include "include/PrimeNumbers.h"

primeNumbers::primeNumbers() { }

primeNumbers::~primeNumbers() { }

std::vector<int> primeNumbers::findPrimeNums(int min, int max) {
    if (min < 0)
        throw "Error! Negative numbers can't be prime!";
    int size = max - min + 1;
    int tmp = min;
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = tmp;
        tmp++;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 2; j <= sqrt((double)arr[i]); j++)
            if (arr[i] % j == 0 && arr[i] != j && arr[i] != 1) {
                arr[i] = 0; // 0 - not a prime number
                break;
            }
    }
    return arr;
}
