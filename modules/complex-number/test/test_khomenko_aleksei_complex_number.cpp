// Copyright 2018 Khomenko Aleksei

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Khomenko_Aleksei_ComplexNumberTest, ReEqlRe) {
    // Arrange
    double re = -1.0;
    double im = 1.0;
    
    // Act
    ComplexNumber z(0.0, im);
    ComplexNumber z1 = z*z;
    
    // Assert
    EXPECT_EQ(re, z1.getRe());
 
}

TEST(Khomenko_Aleksei_ComplexNumberTest, Not_Equal) {
    // Arrange
    double re = 20.0;
    double im = 25.0;
    
    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re-5,im-7);
    
    // Assert
    
    ASSERT_NE(z1, z);
}


