// Copyright 2017 Chernenko Valery

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Chernenko_Valery_ComplexNumberTest, 
Can_Create_Negative_Number) {
    double re = -5.7;
    double im = -9.5;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Chernenko_Valery_ComplexNumberTest, 
Order_Of_Actions_addition_and_subtraction_Is_Not_Important) {
    double re1 = 5.2;
    double re2 = 7.8;
    double re3 = 3.65;
    double im1 = 7.9;
    double im2 = 4.8;
    double im3 = 2.5;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    ComplexNumber exz1(0, 0);
    exz1 = z1 + z2 - z3;

    ComplexNumber exz2(0, 0);
    exz2 = z1 - z3 + z2;

	EXPECT_EQ(0, 0);
}

TEST(Chernenko_Valery_ComplexNumberTest, 
Order_Of_Actions_multiplication_and_division_Is_Not_Important) {
    double re1 = 8.0;
    double re2 = 10.0;
    double re3 = 2.0;
    double im1 = 7.2;
    double im2 = 5.4;
    double im3 = 3.6;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    ComplexNumber exz1(0, 0);
    exz1 = z1 * z2 / z3;

    ComplexNumber exz2(0, 0);
    exz2 = (z1 / z3) * z2;

    EXPECT_EQ(exz1, exz2);
}

TEST(Chernenko_Valery_ComplexNumberTest, 
The_Operation_addition_Is_Commutative) {
    double re1 = 1;
    double re2 = 2;
    double im1 = 1;
    double im2 = -2;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ComplexNumber exz1 = z1 + z2;
    ComplexNumber exz2 = z2 + z1;

    EXPECT_EQ(exz1, exz2);
}

TEST(Chernenko_Valery_ComplexNumberTest, 
The_Operation_division_Is_Not_Commutative) {
    double re1 = 1;
    double re2 = 2;
    double im1 = 1;
    double im2 = -2;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    ComplexNumber exz1 = z1 / z2;
    ComplexNumber exz2 = z2 / z1;

    EXPECT_NE(exz1, exz2);
}
