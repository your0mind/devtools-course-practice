// Copyright 2018 Tipanov Daniil

#include <gtest/gtest.h>
#include <vector>
#include "include/PrimeNumbers.h"

TEST(primeNumbers, can_create_without_error_empty) {
    // AAA
    ASSERT_NO_THROW(primeNumbers tmp);
}

TEST(primeNumbers, can_create_without_error_not_empty) {
    // AAA
    ASSERT_NO_THROW(primeNumbers tmp(2, 5));
}

TEST(primeNumbers, error_if_min_is_less_than_zero) {
    // AAA
    ASSERT_ANY_THROW(primeNumbers tmp(-6, 6));
}

TEST(primeNumbers, error_if_max_is_less_than_min) {
    // AAA
    ASSERT_ANY_THROW(primeNumbers tmp(6, 5));
}

TEST(primeNumbers, find_prime_numbers_without_errors) {
    // Arrange
    primeNumbers tmp(6, 8);

    // Act and assert
    ASSERT_NO_THROW(tmp.findPrimeNums());
}

TEST(primeNumbers, check_result_array) {
    // Arrange
    int min = 3, max = 5;
    std::vector<int> resArr = { 3, 5 };
    primeNumbers tmp(min, max);

    // Act and assert
    EXPECT_EQ(resArr, tmp.findPrimeNums());
}
