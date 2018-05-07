// Copyright 2018 Boris Ermachenko

#include <gtest/gtest.h>

#include "include/Calculation_Rent.h"

TEST(Calculation_Rent_Test, Can_Create_Object) {
    // Assert
    ASSERT_NO_THROW(Calculation_Rent rent_tmp);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_postnumerando_hard_rate) {
    // Arrange
    Calculation_Rent r;
    // Act
    double result = r.Rent_Accum_Year_postnumerando_hard_rate(50, 2, 3);

    // Assert
    EXPECT_EQ(250, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_postnumerando_easy_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Accum_Year_postnumerando_easy_rate(150.4, 20, 10);

    // Assert
    EXPECT_EQ(288768, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_prenumerando_hard_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Accum_Year_prenumerando_hard_rate(10000, 5, 2);

    // Assert
    EXPECT_EQ(3630000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_pretnumerando_easy_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Accum_Year_pretnumerando_easy_rate(120000, 10, 5);

    // Assert
    EXPECT_EQ(34200000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_P_Period_postnumerando) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Accum_P_Period_postnumerando(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(164000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_P_Period_prenumerando) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Accum_P_Period_prenumerando(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(492000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_postnumerando_hard_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_Year_postnumerando_hard_rate(7861, 8, 4);

    // Assert
    EXPECT_EQ(1965.24496896, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_postnumerando_easy_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_Year_postnumerando_easy_rate(10000, 2, 10);

    // Assert
    EXPECT_EQ(1385.28, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_prenumerando_hard_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_Year_prenumerando_hard_rate(50, 200, 3);

    // Assert
    EXPECT_EQ(66.6667, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_pretnumerando_easy_rate) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_Year_pretnumerando_easy_rate(50, 2, 30000);

    // Assert
    EXPECT_EQ(50, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_P_Period_postnumerando) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_P_Period_postnumerando(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(24.9962, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_P_Period_prenumerando) {
    // Arrange
    Calculation_Rent r;

    // Act
    double result = r.Rent_Modern_P_Period_prenumerando(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(74.9886, result);
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_postnumerando_hard_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_postnumerando_hard_rate(0, -1, 6));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_postnumerando_easy_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_postnumerando_easy_rate(0, -1, 0));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_prenumerando_hard_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_prenumerando_hard_rate(0, 0, 2));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_Year_pretnumerando_easy_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_Year_pretnumerando_easy_rate(20000, 10, 0));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_P_Period_postnumerando_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_P_Period_postnumerando(0, 0, 0, 0, 0));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_P_Period_prenumerando_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Accum_P_Period_prenumerando(1, 0, 5, 2, 20000000));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Year_postnumerando_hard_rate_bad_val) {
    // Arrang
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Year_postnumerando_hard_rate(-7861, 8, 4));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Year_postnumerando_easy_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Year_postnumerando_easy_rate(0, 0, 0));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Year_prenumerando_hard_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Yearly_prenumerando_hard_rate(50, -200, 3));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_Yearly_prenumer_easy_rate_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_Yearly_pretnumerando_easy_rate(
                                                20000000000, 2, 3));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_P_Period_postnumerando_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_P_Period_postnumerando(100, -4, -5, 2, 2));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_P_Period_prenumerando_bad_val) {
    // Arrange
    Calculation_Rent r;

    // Act

    // Assert
    ASSERT_ANY_THROW(r.Rent_Modern_P_Period_prenumerando(0, 4, 5, 2, 2));
}
