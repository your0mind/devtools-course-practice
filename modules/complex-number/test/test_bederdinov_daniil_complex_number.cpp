// Copyright 2018 DD

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bederdinov_Daniil_ComplexNumberTest, Can_Create_Zer0) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
