// Copyright 2017 Gladyshev Alexey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Gladyshev_Alexey_ComplexNumberTest, Correct_Associativity) {
	// Arrange
	ComplexNumber z1(0.2, -0.3), z2(12, 17), z3(78.897, -47);

	// Act
	ComplexNumber firstZ = z1 + z2 * z3;
	ComplexNumber secondZ = z1 + (z2 * z3);

	// Assert
	EXPECT_TRUE(firstZ == secondZ);
}