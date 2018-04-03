// Copyright 2018 Panov Aleksander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Panov_Aleksander_ComplexNumberTest, Can_Create_Copy) {
	// Arrange
    double re = -1.0;
    double im = 1.0;
	
	// Act
    ComplexNumber z(re, im);
    ComplexNumber copy_z(z);
	
	// Assert
    EXPECT_EQ(copy_z, z);
}

TEST(Panov_Aleksander_ComplexNumberTest, Can_Multiplication_Real) {
	// Arrange
    double re1 = 3.0, re2 = 4.0;
	
	// Act
    ComplexNumber a(re1, 0.0), b(re2, 0.0);
    ComplexNumber res(re1*re2, 0.0);
	
	// Assert
    EXPECT_EQ(a*b, res);
}

TEST(Panov_Aleksander_ComplexNumberTest, Can_Multiplication_Imaginary) {
	// Arrange
    double im1 = 3.0, im2 = 4.0;
	
	// Act
    ComplexNumber a(0.0, im1), b(0.0, im2);
    ComplexNumber res(-im1*im2, 0.0);
	
	// Assert
    EXPECT_EQ(a*b, res);
}

TEST(Panov_Aleksander_ComplexNumberTest, Can_Division_Real) {
	// Arrange
    double re1 = 12.0, re2 = 3.0;
	
	// Act
    ComplexNumber a(re1, 0.0), b(re2, 0.0);
    ComplexNumber res(re1/re2, 0.0);
	
	// Assert
    EXPECT_EQ(a/b, res);
}

TEST(Panov_Aleksander_ComplexNumberTest, Can_Division_Imaginary) {
	// Arrange
    ComplexNumber z1(0.0, 4.0);
    ComplexNumber z2(0.0, 2.0);
	
	// Act
    ComplexNumber res(2.0, 0.0);
	
	// Assert
    EXPECT_EQ(z1 / z2, res);
}
