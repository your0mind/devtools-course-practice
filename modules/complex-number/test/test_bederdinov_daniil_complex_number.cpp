// Copyright 2018 Bederdinov Daniil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bederdinov_Daniil_ComplexNumberTest, Can_Multiply_By_Zero) {
    // Arrange
    ComplexNumber z(7.1488, 13.22);

    // Act
    ComplexNumber z1 = z * 0;

    // Assert
    EXPECT_EQ(0,z1);
}

TEST(Bederdinov_Daniil_ComplexNumberTest,
    Can_Subtract_Complex_Nubmer_From_Itself) {
    // Arrange
    ComplexNumber z(7.1483, 13.32);

    // Act
    ComplexNumber z1 = z - z;

    // Assert
    EXPECT_EQ(0, z1);
}

TEST(Bederdinov_Daniil_ComplexNumberTest,
    Multiplification_By_One_Changes_Nothing) {
    // Arrange
    ComplexNumber z(7.1483, 13.32);

    // Act
    ComplexNumber z1 = z * 1;

    // Assert
    EXPECT_EQ(z1, z1);
}

TEST(Bederdinov_Daniil_ComplexNumberTest,
    Return_One_When_Divided_By_Itself) {
    // Arrange
    ComplexNumber z(7.1483, 13.32);

    // Act
    ComplexNumber z1 = z / z;

    // Assert
    EXPECT_EQ(1, z1);
}

TEST(Bederdinov_Daniil_ComplexNumberTest, Can_Add_Zero) {
    // Arrange
    ComplexNumber z(7.1483, 13.32);

    // Act
    ComplexNumber z1 = z + 0;

    // Assert
    EXPECT_EQ(z1, z);
}