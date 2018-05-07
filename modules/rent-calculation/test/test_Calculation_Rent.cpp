// Copyright 2018 Boris Ermachenko

#include <gtest/gtest.h>

#include "include/Calculation_Rent.h"

TEST(Calculation_Rent_Test, Can_Create_Object) {
    // Assert
    ASSERT_NO_THROW(Calculation_Rent rent_tmp);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_postnum_hard_rate) {
    // Arrange
    Calculation_Rent r;
    // Act
    double result = r.Rent_Accum_Year_postnum_hard_rate(50, 2, 3);

    // Assert
    EXPECT_EQ(250, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_postnum_easy_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Accum_Year_postnum_easy_rate(150.4, 20, 10);

    // Assert
    EXPECT_EQ(288768, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_prenum_hard_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Accum_Year_prenum_hard_rate(10000, 5, 2);

    // Assert
    EXPECT_EQ(3630000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_prenum_easy_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Accum_Year_prenum_easy_rate(120000, 10, 5);

    // Assert
    EXPECT_EQ(34200000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_P_Period_postnum) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Accum_P_Period_postnum(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(164000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_P_Period_prenum) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Accum_P_Period_prenum(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(492000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_postnum_hard_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_Year_postnum_hard_rate(7861, 8, 4);

    // Assert
    EXPECT_EQ(1965.24496896, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_postnum_easy_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_Year_postnum_easy_rate(10000, 2, 10);

    // Assert
    EXPECT_EQ(1385.28, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_prenum_hard_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_Year_prenum_hard_rate(50, 200, 3);

    // Assert
    EXPECT_EQ(66.6667, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_prenum_easy_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_Year_prenum_easy_rate(50, 2, 30000);

    // Assert
    EXPECT_EQ(50, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_P_Period_postnum) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_P_Period_postnum(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(24.9962, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_P_Period_prenum) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_P_Period_prenum(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(74.9886, result);
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_postnum_hard_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_postnum_hard_rate(0, -1, 6));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_postnum_hard_rate_bad_val2) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_postnum_hard_rate(200000000, 1, 6));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_postnum_easy_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_postnum_easy_rate(0, -1, 0));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_postnum_easy_rate_bad_val2) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_postnum_easy_rate(200000000, 1, 1));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_prenum_hard_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_prenum_hard_rate(0, 0, 2));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_prenum_hard_rate_bad_val2) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_prenum_hard_rate(200000000, 2, 2));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_prenum_easy_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_prenum_easy_rate(20000, 10, 0));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_prenum_easy_rate_bad_val2) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_prenum_easy_rate(200000000, 10, 1));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_P_Period_postnum_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_P_Period_postnum(0, 0, 0, 0, 0));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_P_Period_postnum_bad_val2) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_P_Period_postnum(200000000, 1, 1, 1, 1));
}
TEST(Calc_Rent_Test, no_Calc_Rent_Accum_P_Period_prenum_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_P_Period_prenum(1, 0, 5, 2, 20000000));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_P_Period_prenum_bad_val2) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_P_Period_prenum(1, 1, 5, 2, 200000000));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Year_postnum_hard_rate_bad_val) {
    // Arrang
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Year_postnum_hard_rate(-7861, 8, 4));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Year_postnum_hard_rate_bad_val2) {
    // Arrang
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Year_postnum_hard_rate(200000000, 8, 4));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Year_postnum_easy_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Year_postnum_easy_rate(0, 0, 0));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Year_postnum_easy_rate_bad_val2) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Year_postnum_easy_rate(200000000, 1, 1));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Year_prenum_hard_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Year_prenum_hard_rate(50, -200, 3));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Year_prenum_hard_rate_bad_val2) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Year_prenum_hard_rate(50, 200000000, 3));
}
TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Year_prenumer_easy_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Year_prenum_easy_rate(
                                                20000000000, 2, 3));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Year_prenumer_easy_rate_bad_val2) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Year_prenum_easy_rate(
        20000, 0, 3));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_P_Period_postnum_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_P_Period_postnum(100, -4, -5, 2, 2));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_P_Period_postnum_bad_val2) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_P_Period_postnum(100, 300000000, 5, 2, 2));
}
TEST(Calc_Rent_Test, no_Calc_Rent_Modern_P_Period_prenum_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_P_Period_prenum(0, 4, 5, 2, 2));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_P_Period_prenum_bad_val2) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_P_Period_prenum(200000000, 4, 5, 2, 2));
}
