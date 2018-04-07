// Copyright 2018 Senina Anastasia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(senina_anastasia_ComplexNumberTest, Can_add_complex_number) {
    ComplexNumber z0(2.0, 3.7);
    ComplexNumber z1(-2.0, 0.3);
    ComplexNumber res(0.0, 4.0);

    EXPECT_EQ(res, z0 + z1);
}

TEST(senina_anastasia_ComplexNumberTest, Check_a_property_of_distributivity) {
    ComplexNumber z0(2.0, 3.7);
    ComplexNumber z1(2.0, 0.3);
    ComplexNumber z2(3.0, 4.0);
    ComplexNumber z3 = z0 * z2 + z1 * z2;
    ComplexNumber res = (z0 + z1) * z2;

    EXPECT_NEAR(res.getRe(), z3.getRe(), 0.001);
    EXPECT_NEAR(res.getIm(), z3.getIm(), 0.001);
}

TEST(senina_anastasia_ComplexNumberTest,
    The_quotient_of_an_imaginary_number_is_a_real_number) {
    ComplexNumber z0(0.0, 4.0);
    ComplexNumber z1(0.0, 2.0);
    ComplexNumber res(2.0, 0.0);

    EXPECT_EQ(res, z0/z1);
}

TEST(senina_anastasia_ComplexNumberTest,
    Correct_mult_imaginary_numbers_of_identical_signs) {
    ComplexNumber z0(0.0, 4.0);
    ComplexNumber z1(0.0, 2.0);
    ComplexNumber res(-8.0, 0.0);

    EXPECT_EQ(res, z0 * z1);
}

TEST(senina_anastasia_ComplexNumberTest,
    Correct_mult_three_imaginary_numbers_of_different_signs) {
    ComplexNumber z0(0.0, 4.0);
    ComplexNumber z1(0.0, -2.0);
    ComplexNumber z2(0.0, 1.0);
    ComplexNumber res(0.0, 8.0);

    EXPECT_EQ(res, z0 * z1*z2);
}

TEST(senina_anastasia_ComplexNumberTest, Check_a_property_of_commutativity) {
    ComplexNumber z0(1.0, 4.0);
    ComplexNumber z1(3.0, -2.0);
    ComplexNumber z_res1 = z0 * z1;
    ComplexNumber z_res2 = z1 * z0;

    EXPECT_TRUE(z_res1 == z_res2);
}
