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

TEST(Shurygin_Dmitriy_ComplexNumberTest, dif_is_zero) {
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.0, 2.0);

    ComplexNumber z = z1 - z2;
    EXPECT_EQ(0, z.getRe());
    EXPECT_EQ(0, z.getIm());
}

TEST(Shurygin_Dmitriy_ComplexNumberTest, Can_Get_Im_and_Re) {
    double re = 3;
    double im = -1.23;

    ComplexNumber z(re, im);
    EXPECT_EQ(im, z.getIm());
    EXPECT_EQ(re, z.getRe());
}

TEST(Shurygin_Dmitriy_ComplexNumberTest, Can_Copy) {
    double re = 3;
    double im = -1.23;
    
    ComplexNumber z(re, im);
    ComplexNumber copy_z(z);
    
    EXPECT_EQ(z, copy_z);
}

TEST(Shurygin_Dmitriy_ComplexNumberTest, Division_by_himself) {
    double re = 3;
    double im = -1.23;
    
    ComplexNumber z(re, im);
    ComplexNumber z1(1.0, 0);
	ComplexNumber res = z / z;
    EXPECT_EQ(res, z1);
}

TEST(Shurygin_Dmitiy_ComplexNumberTest, cant_divide_zero) {
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2;
    
    ASSERT_ANY_THROW(z1 / z2);
}