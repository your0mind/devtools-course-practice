// Copyright 2017 Gladyshev Alexey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Gladyshev_Alexey_ComplexNumberTest, Can_Create_Zero) {
	// Arrange
	double re = 0.0;
	double im = 0.0;

	// Act
	ComplexNumber z(re, im);

	// Assert
	EXPECT_EQ(re, z.getRe());
	EXPECT_EQ(im, z.getIm());
}