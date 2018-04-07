// Copyright 2017 Kiselev Denis

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kiseled_Denis_ComplexNumberTest, Can_Create_Not_Zero) {
    // Arrange
    double re = 1.1;
    double im = 2.2;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
