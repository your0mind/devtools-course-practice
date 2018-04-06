// Copyright 2018 Vyunov Roman
#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vyunov_Roman_ComplexNumberTest, Triple_Operetor_equally) {
  double re=32.111;
  double im=11.212;

  ComplexNumber t1(re, im);
  ComplexNumber t2;
  ComplexNumber t3;

  t2=t3=t1;

  EXPECT_EQ(t1, t2);
}

TEST(Vyunov_Roman_ComplexNumberTest, Complex_Division) {
  double re1=32.111;
  double im1=11.212;
  double re2=13.1111;
  double im2=11.2121;
  double re3=13.1109;
  double im3=11.2128;

  ComplexNumber t1(re1, im1);
  ComplexNumber t2(re2, im2);
  ComplexNumber t3(re3, im3);

  EXPECT_NO_THROW(t1/(t2-t3));
}
