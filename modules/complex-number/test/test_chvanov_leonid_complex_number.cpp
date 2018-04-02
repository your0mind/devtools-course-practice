// Copyright 2018 Chvanov Leonid

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Chvanov_Leonid_ComplexNumberTest, Check_Commutative_Property_Of_Addition) {
    // Arrange
	ComplexNumber z1(5.0, 6.0);
	ComplexNumber z2(15.0, 16.0);

    // Act
	ComplexNumber sum1(z1 + z2);
	ComplexNumber sum2(z2 + z1);

    // Assert
	EXPECT_EQ(sum1, sum2);
}

TEST(Chvanov_Leonid_ComplexNumberTest, Check_Distributive_Property_Of_Addition) {
	// Arrange
	ComplexNumber z1(5.0, 6.0);
	ComplexNumber z2(15.0, 16.0);
	ComplexNumber z3(115.0, 116.0);

	// Act
	ComplexNumber sum1(z1 * (z2 + z3));
	ComplexNumber sum2(z1 * z2  + z1 * z3);

	// Assert
	EXPECT_EQ(sum1, sum2);
}