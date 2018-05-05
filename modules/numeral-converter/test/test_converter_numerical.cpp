// Copyright 2018 Novikova Alisa
#include <gtest/gtest.h>
#include "converter-numerical.h"



TEST(Numerical_Converter_Test, Can_Create_Object) {
	// Assert
	ASSERT_NO_THROW(NumericalConverter temp);
}
TEST(Numerical_Converter_Test, Can_Convert_Roman_To_Arabic) {
	// Arrange
	string input = "M";
	NumericalConverter temp;
	// Act	
	double result = temp.ConvertRomanNumeralToArabicNumberRefactored(input);
	// Assert
	EXPECT_EQ(1000, result);
}
TEST(Numerical_Converter_Test, Can_Convert_One_To_Arabic) {
	// Arrange
	string input = "I";
	NumericalConverter temp;
	// Act
	double result = temp.ConvertOneToArabicNumber(input);
	// Assert
	EXPECT_EQ(1, result);
}
TEST(Numerical_Converter_Test, Can_Convert_Nine_To_Arabic) {
	// Arrange
	string input = "IX";
	NumericalConverter temp;
	// Act
	double result = temp.ConvertRomanNumeralToArabicNumber(input);
	// Assert
	EXPECT_EQ(9, result);
}
TEST(Numerical_Converter_Test, Can_Convert_One_To_Roman_Numeral) {
	// Arrange
	double input = 1;
	NumericalConverter temp;
	// Act
	string result = temp.ConvertOneToRomanNumeral(input);
	// Assert
	EXPECT_EQ("I", result);
}
TEST(Numerical_Converter_Test, Can_Convert_Three_To_Roman_Numeral) {
	// Arrange
	double input = 3;
	NumericalConverter temp;
	// Act
	string result = temp.ConvertThreeToRomanNumeral(input);
	// Assert
	EXPECT_EQ("III", result);
}
TEST(Numerical_Converter_Test, Can_Convert_To_Roman_Numeral) {
	// Arrange
	double input = 66;
	NumericalConverter temp;
	// Act
	string result = temp.ConvertToRomanNumeral(input);
	// Assert
	EXPECT_EQ("LXVI", result);
}
