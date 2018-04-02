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
