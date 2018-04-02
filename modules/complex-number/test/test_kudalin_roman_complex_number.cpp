// Copyright 2018 Kudalin Roman

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kudalin_Roman_ComplexNumberTest, Addition_Is_Associative) {
    // Arrange
    ComplexNumber z1(15.0, 23.0);
    ComplexNumber z2(9.4, 17.9);
    ComplexNumber z3(13.3, 5.5);
    
    // Act
    ComplexNumber sum1 = z1 + (z2 + z3);
    ComplexNumber sum2 = (z1 + z2) + z3;
    
    // Assert
    EXPECT_EQ(sum1, sum2);
}