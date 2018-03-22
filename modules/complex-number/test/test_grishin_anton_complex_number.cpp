// Copyright 2018 Grishin Anton

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Grishin_Anton_ComplexNumberTest, Can_get_Re_from_Im) {
	// Arrange
	double re = -1.0;
	double im = 1;

	// Act
	ComplexNumber z1(0.0, im);

	ComplexNumber z = z1 * z1;

	// Assert
	EXPECT_EQ(re, z.getRe());
}