// Copyright 2018 Razumova Maria

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Razumova_Maria_ComplexNumberTest, Order_of_sum_is_not_important ) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;

    double re2 = 1.0;
    double im2 = 3.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_EQ(z1 + z2, z2 + z1);
}

TEST(Razumova_Maria_ComplexNumberTest, Number_divided_by_1_stays_same ) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;

    double re2 = 1.0;
    double im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_EQ(z1 / z2, z1);
}

