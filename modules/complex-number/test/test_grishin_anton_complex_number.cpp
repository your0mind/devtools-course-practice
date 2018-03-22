// Copyright 2018 Grishin Anton

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Grishin_Anton_ComplexNumberTest, Can_Negative_Number) {
	// Arrange
	double re = 5.0;
	double im = 5.0;

	// Act
	ComplexNumber z(re, im);
	

	// Assert
	EXPECT_EQ(re, z.getRe());
	EXPECT_EQ(im, z.getIm());
}