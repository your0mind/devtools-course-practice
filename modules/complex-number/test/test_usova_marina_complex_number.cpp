// Copyright 2018 Usova Marina

#include <gtest/gtest.h>

#include "include/complex_number.h"

double epsilon = 0.001;

TEST(Usova_Marina_ComplexNumberTest, Can_Set_Im_and_Re) {
  // Arrange
  double re = 15.5;
  double im = -5.5;

  ComplexNumber z;

  // Act
  z.setRe(re);
  z.setIm(im);

  // Assert
  EXPECT_NEAR(re, z.getRe(), epsilon);
  EXPECT_NEAR(im, z.getIm(), epsilon);
}

TEST(Usova_Marina_ComplexNumberTest, Can_Get_Im_and_Re) {
  // Arrange
  double re = 15.5;
  double im = -5.5;

  // Act
  ComplexNumber z(re, im);

  // Assert
  EXPECT_NEAR(z.getRe(), re, epsilon);
  EXPECT_NEAR(z.getIm(), im, epsilon);
}

TEST(Usova_Marina_ComplexNumberTest, Can_Use_Ñopy_Ñonstructor) {
  // Arrange
  double re = 5.0;
  double im = 15.0;

  // Act
  ComplexNumber z(re, im);

  // Assert
  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Usova_Marina_ComplexNumberTest, Can_Use_Default_Constructor) {
  // Act
  ComplexNumber z;

  // Assert
  EXPECT_EQ(0, z.getRe());
  EXPECT_EQ(0, z.getIm());
}

TEST(Usova_Marina_ComplexNumberTest, Can_Use_Assigment_Constructor) {
  // Arrange
  ComplexNumber z1(5.0, 15.0);

  // Act
  ComplexNumber z2(z1);

  // Assert
  EXPECT_EQ(z2, z1);
}