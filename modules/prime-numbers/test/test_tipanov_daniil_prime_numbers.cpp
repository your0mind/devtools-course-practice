// Copyright 2018 Tipanov Daniil

#include <gtest/gtest.h>
#include "include/PrimeNumbers.h"

TEST(primeNumbers, error_if_min_is_less_than_zero) {
    // Arrange
    primeNumbers tmp;

    // Act and assert
    ASSERT_ANY_THROW(tmp.findPrimeNums(-6, 6));
}

TEST(primeNumbers, execute_without_errors) {
    // Arrange
    primeNumbers tmp;

    // Act and assert
    ASSERT_NO_THROW(tmp.findPrimeNums(6, 66));
}

TEST(primeNumbers, check_result_array) {
    // Arrange
    int min = 3, max = 5;
    std::vector<int> resArr = { 3, 0, 5 };
    primeNumbers tmp;

    // Act and assert
    EXPECT_EQ(resArr, tmp.findPrimeNums(min, max));
}
