// Copyright 2017 Khomenko Aleksei

#include <gtest/gtest.h>
#include <string>
#include "include/fractional_numbers.h"


TEST(FractionNumbersTest, Can_Create_With_Chislitel_And_Znamenatel) {
    // Arrange
    int chislitel = 5;
    int znamenatel = 6;

    // Act
    Rational r(chislitel, znamenatel);

    // Assert
    EXPECT_EQ(chislitel, r.getChislitel());
    EXPECT_EQ(znamenatel, r.getZnamenatel());
}

TEST(FractionNumbersTest, Can_Create_Via_Copying) {
    // Arrange
    Rational r(50, 60);

    // Act
    Rational expected_r = r;

    // Assert
    EXPECT_EQ(expected_r, r);
}

TEST(FractionNumbersTest, Can_Create_Via_Assignment) {
    // Arrange
    Rational r(50, 60);
    Rational expected_r;

    // Act
    r = expected_r;

    // Assert
    EXPECT_EQ(expected_r, r);
}

TEST(FractionNumbersTest, Can_Create_const) {
    // Arrange
    Rational r1(1, 2);
    Rational r2(1, 2);
    Rational res_r(1, 1);

    // Act
    Rational r = r1 + r2;

    // Assert
    EXPECT_EQ(r, res_r);
}

TEST(FractionNumbersTest, Number_Is_Equal) {
    // Arrange
    Rational r1;
    Rational r2(0, 1);

    // Act & Assert
    EXPECT_TRUE(r1 == r2);
}

TEST(FractionNumbersTest, Can_Add_Rational) {
    // Arrange
    Rational r1(1, 5), r2(12, 43);

    // Act
    Rational r = r1 + r2;

    // Assert
    Rational expected_r(103, 215);
    EXPECT_EQ(expected_r, r);
}

TEST(FractionNumbersTest, Can_Difference_Rational) {
    // Arrange
    Rational r1(75, 165);
    Rational r2(87, 170);

    // Act
    Rational r = r1 - r2;

    // Assert
    Rational expected_r(-1605, 28050);
    EXPECT_EQ(expected_r, r);
}
TEST(FractionNumbersTest, Can_Set_Chislitel) {
    // Arrange
    Rational r;
    int chislitel = 35;

    // Act
    r.setChislitel(chislitel);

    // Assert
    EXPECT_EQ(chislitel, r.getChislitel());
}

TEST(FractionNumbersTest, Can_Set_Znamenatel) {
    // Arrange
    Rational r;
    int znamenatel = 26.0;

    // Act
    r.setZnamenatel(znamenatel);

    // Assert
    EXPECT_EQ(znamenatel, r.getZnamenatel());
}

TEST(FractionNumbersTest, Can_Multiplication_Rational) {
    // Arrange
    Rational r1(15, 37);
    Rational r2(3, 17);

    // Act
    Rational r = r1 * r2;

    // Assert
    Rational expected_r(45, 629);
    EXPECT_EQ(expected_r, r);
}

TEST(FractionNumbersTest, Can_Division_Rational) {
    // Arrange
    Rational r1(23, 54);
    Rational r2(-135, 23);

    // Act
    Rational r = r2 / r1;

    // Assert
    Rational expected_r(-7290, 529);
    EXPECT_EQ(expected_r, r);
}

TEST(FractionNumbersTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    Rational r1(0, 6);
    Rational r2(12, 45);

    // Act & Assert
    EXPECT_THROW(r2 / r1, std::string);
}

TEST(FractionNumbersTest, Number_Is_Equal_To_Itself) {
    // Arrange
    Rational r(50, 194);

    // Act & Assert
    EXPECT_TRUE(r == r);
}

TEST(FractionNumbersTest, Equal_Numbers_Are_Equal) {
    // Arrange
    Rational r1(1, 8);
    Rational r2(1, 8);

    // Act & Assert
    EXPECT_EQ(r1, r2);
}

TEST(FractionNumbersTest, Not_Equal_Numbers_Are_Not_Equal) {
    // Arrange
    Rational r1(1, 2);
    Rational r2(1, 4);

    // Act & Assert
    EXPECT_FALSE(r1 == r2);
}

TEST(FractionNumbersTest, Do_Create_Throw) {
    // Arrange & Act & Assert
    EXPECT_THROW(Rational r1(1, 0), std::string);
}
