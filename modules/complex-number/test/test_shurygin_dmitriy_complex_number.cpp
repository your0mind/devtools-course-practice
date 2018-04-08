// Copyright 2018 Shurygin Dmitriy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shurygin_Dmitriy_ComplexNumberTest, Can_Create_Zero) {
    double re = 0.0;
    double im = 0.0;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Shurygin_Dmitriy_ComplexNumberTest, Is_Equal) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.0, 2.0);
	
    ComplexNumber z = z1 - z2;
	
    EXPECT_EQ(0, z.getRe());
    EXPECT_EQ(0, z.getIm());
}

TEST(Shurygin_Dmitriy_ComplexNumberTest, Can_Get_Im) {
    double re = 3;
    double im = -1.23;
	
    ComplexNumber z(re, im);

    EXPECT_EQ(im, z.getIm());
    EXPECT_EQ(re, z.getRe());
}

