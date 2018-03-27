// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>
#include <iostream>
#include "ComplexNumber.h"
using namespace std;

TEST(Korniakov_Kirill_ComplexNumberTest, Can_Create_Zero) {
	// Arrange
	double re = 0.0;
	double im = 0.0;

	// Act
	ComplexNumber z(re, im);

	// Assert
	EXPECT_EQ(re, z.getRe());
	EXPECT_EQ(im, z.getIm());
}

TEST(Nifadyev_Vadim_ComplexNumberTest, Can_Multiply_By_Zero) {
    ComplexNumber number1(-454.9, 35.646), number2(0.0, 0.0);

    ComplexNumber result = number1 * number2;
    ComplexNumber expectedResult(0.0, 0.0);

    EXPECT_EQ(result, expectedResult);
}

TEST(Nifadyev_Vadim_ComplexNumberTest, Can_Add_Complex_Numbers_With_Huge_Real_Part)
{
    ComplexNumber number1(DBL_MAX, -435.0), number2(DBL_MAX, 8769.7);

    ComplexNumber result = number1 + number2;
    ComplexNumber expectedResult(INFINITY, 8334.7);

    EXPECT_DOUBLE_EQ(result.getRe(), expectedResult.getRe());
    EXPECT_DOUBLE_EQ(result.getIm(), expectedResult.getIm());
}

TEST(Nifadyev_Vadim_ComplexNumberTest, Can_Get_Infinity_By_Adding_Two_Huge_Comlex_Numbers)
{
    ComplexNumber number1(DBL_MAX, DBL_MAX), number2(DBL_MAX, DBL_MAX);

    ComplexNumber result = number1 + number2;
    ComplexNumber expectedResult(INFINITY, INFINITY);

    EXPECT_DOUBLE_EQ(result.getRe(), expectedResult.getRe());
    EXPECT_DOUBLE_EQ(result.getIm(), expectedResult.getIm());
}

TEST(Nifadyev_Vadim_ComplexNumberTest, sCan_Get_Infinity_By_Adding_Two_Huge_Comlex_Numbers)
{
    //TODO: change
    ComplexNumber number1(DBL_MIN, DBL_MIN), number2(DBL_MAX, DBL_MAX);

    ComplexNumber result = number1 - number2;
    ComplexNumber expectedResult(-DBL_MAX, -DBL_MAX);

    EXPECT_DOUBLE_EQ(result.getRe(), expectedResult.getRe());
    EXPECT_DOUBLE_EQ(result.getIm(), expectedResult.getIm());
}
