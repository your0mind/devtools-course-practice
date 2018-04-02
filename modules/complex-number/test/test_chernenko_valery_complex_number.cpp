// Copyright 2017 Chernenko Valery

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Chernenko_Valery_ComplexNumberTest, Can_Create_Negative_Number) {

    Double re = -5.7;
    Double im = -9.5;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Chernenko_Valery_ComplexNumberTest, Order_Of_Actions_+_and_-_Is_Not_Important) {
    
    ComplexNumber z1(5.2, 7.9);
    ComplexNumber z2(7.8, 4.6);
    ComplexNumber z3(6.7, 2.8);

    ComplexNumber exz1 = z1 + z2 - z3;
    ComplexNumber exz2 = z1 - z3 + z2;

    EXPECT_EQ(exz1, exz2);
}

TEST(Chernenko_Valery_ComplexNumberTest, Order_Of_Actions_*_and_/_Is_Not_Important) {
    
    ComplexNumber z1(5.2, 7.9);
    ComplexNumber z2(7.8, 4.6);
    ComplexNumber z3(6.7, 2.8);

    ComplexNumber exz1 = z1 * z2 / z3;
    ComplexNumber exz2 = z1 / z3 * z2;

    EXPECT_EQ(exz1, exz2);
}

TEST(Chernenko_Valery_ComplexNumberTest, The_Operation_+_Is_Commutative) {

    ComplexNumber z1(1 , 1);
    ComplexNumber z2(2 , -2);

    ComplexNumber exz1 = z1 + z2;
    ComplexNumber exz2 = z2 + z1;

    EXPECT_EQ(exz1, exz2);
}

TEST(Chernenko_Valery_ComplexNumberTest, The_Operation_/_Is_Not_Commutative) {

    ComplexNumber z1(1 , 1);
    ComplexNumber z2(2 , -2);

    ComplexNumber exz1 = z1 / z2;
    ComplexNumber exz2 = z2 / z1;

    EXPECT_NE(exz1, exz2);
}
