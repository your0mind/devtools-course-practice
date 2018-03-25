// Copyright 2018 Khomenko Aleksei

#include <gtest/gtest.h>

#include "include/complex_number.h"
//#include <math.h>

TEST(Khomenko_Aleksei_ComplexNumberTest, Re_Eql_Re) {
    // Arrange
    double re = -1.0;
    double im = 1.0;
    
    // Act
    ComplexNumber z(0.0, im);
    ComplexNumber z1 = z*z;
    
    // Assert
    EXPECT_EQ(re, z1.getRe());
 
}

TEST(Khomenko_Aleksei_ComplexNumberTest, RNot_Equal) {
    // Arrange
    double re = 20.0;
    double im = 25.0;
    
    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re-5,im-5);
    
    // Assert
    ASSERT_NE(z1.getRe(), z.getRe());
    ASSERT_NE(z1.getIm(), z.getIm());
}

TEST(Khomenko_Aleksei_ComplexNumberTest, Add_Zero) {
    // Arrange
    double re = 20.0;
    double im = 25.0;
    
  //  double __z__= sqrt(re*re+im*im);
    
    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z_res = z + z1;
    
    // Assert
    ASSERT_EQ(z_res.getRe(), z.getRe());
    ASSERT_EQ(z_res.getIm(), z.getIm());
}


