// Copyright 2018 Kozorez Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kozorez_Alex_ComplexNumberTest, 
     complex_plus_zero_is_equal_to_this_complex){
    
    // Act
    ComplexNumber z(666.0, 22.0), z1(0.0,0.0);
    ComplexNumber sum = z + z1;
    
    // Assert 
    EXPECT_EQ(z, sum);
}

TEST(Kozorez_Alex_ComplexNumberTest, multi_by_zero_is_zero) {
    // Arrange 
    ComplexNumber z(666.0, 22.0), z1(0.0, 0.0);
    ComplexNumber zero(0.0, 0.0);
     
    // Act
    ComplexNumber multi = z * z1;
    
    // Assert
    EXPECT_EQ(multi, zero);
}

TEST(Kozorez_Alex_ComplexNumberTest, sum_commutication) {
    // Arrange 
    ComplexNumber z(66.0, 22.0), z1(-66.0, -22.0);
     
    // Assert 
    EXPECT_EQ(z+z1, z1+z);
}

TEST(Kozorez_Alex_ComplexNumberTest, sum_of_equals_by_abs_is_zero) {
    // Arrange 
    ComplexNumber z(666.0, 22.0), z1(-666.0, -22.0);
    ComplexNumber zero(0.0, 0.0);
    
    // Act
    ComplexNumber zero1 = z + z1;
    
    // Assert 
    EXPECT_EQ(zero, zero1);
}

TEST(Kozorez_Alex_ComplexNumberTest, multiply_comm) {
    // Arrange 
    ComplexNumber z(66.0, 22.0), z1(-66.0, -22.0);
     
    // Assert 
    EXPECT_EQ(z*z1, z1*z);
}
