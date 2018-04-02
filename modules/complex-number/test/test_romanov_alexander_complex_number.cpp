// Copyright 2018 Romanov Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Romanov_Alexander_ComplexNumberTest, Can_init_complex_number) {
    ComplexNumber z(1.0, -1.0);
    EXPECT_EQ(z.getRe(), 1.0);
    EXPECT_EQ(z.getIm(), -1.0);
}
TEST(Romanov_Alexander_ComplexNumberTest, cant_divide_zero) {
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2;
    ASSERT_ANY_THROW(z1 / z2);
}
TEST(Romanov_Alexander_ComplexNumberTest, able_equal_copying) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2 = z1;
    ASSERT_EQ(z1, z2);
}
TEST(Romanov_Alexander_ComplexNumberTest, able_distribution_law) {
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(2.0, 2.0);
    ComplexNumber z3(3.0, 3.0);
    ComplexNumber res1 = z1 * (z2 + z3);
    ComplexNumber res2 = z1 * z2 + z1 * z3;
    EXPECT_TRUE(res1 == res2);
}
TEST(Romanov_Alexander_ComplexNumberTest, can_count_correctly) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(2.0, -2.0);
    ComplexNumber z3(2.0, 2.0);
    ComplexNumber z4(1.0, 0.0);
    ComplexNumber res(6.0, 6.0);
    ASSERT_EQ(res, (z1 + z2) * z3 / z4);
}
