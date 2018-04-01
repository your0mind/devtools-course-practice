// Copyright 2018 Rodionov Fedor

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Rodionov_Fedor_ComplexNumberTest, degree_of_i) {
	// Arrange
	ComplexNumber z1(0.0, 1.0);
	// Act
	ComplexNumber z = z1 * z1 * z1 * z1;
	// Assert
	EXPECT_EQ(1, z.getRe());
}

TEST(Rodionov_Fedor_ComplexNumberTest, find_argument) {
	// Arrange
	ComplexNumber z1(5.0, 5.0);
	double tg_fi = 1;
	// Act
	double z = z1.getRe() / z1.getIm();
	// Assert
	EXPECT_EQ(tg_fi, z);
}