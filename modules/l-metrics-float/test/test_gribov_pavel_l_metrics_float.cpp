// Copyright 2017 Gribov Pavel

#include <gtest/gtest.h>

#include <vector>
#include "include/l-metrics-float.h"

namespace MyEpsilon {
    float eps = 0.001f;
}  // namespace MyEpsilon

TEST(Gribov_Pavel_LMetricsFloatTest, Linf_Dist_IsCorrect) {
    // Arrange
    std::vector<float> vec1 = { 2.4f, -7.8f, -1.3f };
    std::vector<float> vec2 = { -9.2f, -1.5f, 8.0f };

    // Act
    float res = LMetricsFloat::linf_vec_distance(vec1, vec2);

    // Assert
    float expected_res = 11.6f;
    EXPECT_NEAR(expected_res, res, MyEpsilon::eps);
}

TEST(Gribov_Pavel_LMetricsFloatTest, L1_Dist_IsCorrect) {
    // Arrange
    std::vector<float> vec1 = { 1.0f, 1.4f, -3.7f };
    std::vector<float> vec2 = { -4.0f, -5.1f, 3.8f, 0.0f };

    // Act
    float res = LMetricsFloat::l1_vec_distance(vec1, vec2);

    // Assert
    float expected_res = 19.0f;
    EXPECT_NEAR(expected_res, res, MyEpsilon::eps);
}

TEST(Gribov_Pavel_LMetricsFloatTest, L2_Dist_IsCorrect) {
    // Arrange
    std::vector<float> vec1 = { 1.0f, 1.0f, 0.0f };
    std::vector<float> vec2 = { 4.0f, 5.0f };

    // Act
    float res = LMetricsFloat::l2_vec_distance(vec1, vec2);

    // Assert
    float expected_res = 5.0f;
    EXPECT_NEAR(expected_res, res, MyEpsilon::eps);
}

TEST(Gribov_Pavel_LMetricsFloatTest, L3_Dist_IsCorrect) {
    // Arrange
    std::vector<float> vec1 = { 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
    std::vector<float> vec2 = { 0.0f, -2.075f, 0.0f };

    // Act
    float res = LMetricsFloat::l3_vec_distance(vec1, vec2);

    // Assert
    float expected_res = 3.3f;
    EXPECT_NEAR(expected_res, res, MyEpsilon::eps);
}

TEST(Gribov_Pavel_LMetricsFloatTest, L4_Dist_IsCorrect) {
    // Arrange
    std::vector<float> vec1 = { 1.1f, 2.2f, 3.3f };
    std::vector<float> vec2 = { -4.4f, 5.5f, -6.6f };

    // Act
    float res = LMetricsFloat::l4_vec_distance(vec1, vec2);

    // Assert
    float expected_res = 10.156f;
    EXPECT_NEAR(expected_res, res, MyEpsilon::eps);
}
