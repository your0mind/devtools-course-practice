// Copyright 2018 Kuznetsov Konstantin

#include <gtest/gtest.h>

#include <vector>
#include "include/probability_distribution.h"

TEST(ProbabilityDistributionTest, Can_Create_DescretePD) {
    EXPECT_NO_THROW(DescretePD dpd);
}

TEST(ProbabilityDistributionTest, Can_Create_DescretePD_Using_PMF) {
    std::vector<double> values = {1.0, 3.0, 7.0};
    std::vector<double> probabilities = {0.2, 0.5, 0.3};
    // both vectors define probability mass function

    EXPECT_NO_THROW(DescretePD dpd(values, probabilities));
}

TEST(ProbabilityDistributionTest, Throws_When_Vectors_Do_Not_Match) {
    std::vector<double> values = {1.0, 3.0};  // size = 2
    std::vector<double> probabilities = {0.2, 0.5, 0.3};  // size = 3

    EXPECT_ANY_THROW(DescretePD dpd(values, probabilities));
}
