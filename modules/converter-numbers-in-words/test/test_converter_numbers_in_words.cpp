// Copyright 2018 Usova Marina

#include <gtest/gtest.h>

#include <string>

#include "include/converter_numbers_in_words.h"

class ConverterNumbersInWordsTest : public ::testing::Test {
 protected:
  double epsilon = 0.0001;
};

TEST_F(ConverterNumbersInWordsTest, Can_Use_Default_Constructor) {
  // Act
  ConverterNumbersInWords converter;

  // Assert
  EXPECT_EQ(0, converter.GetNumber());
}

TEST_F(ConverterNumbersInWordsTest, Can_Use_Copy_Constructor) {
  // Arrange
  double number = 123.0;

  // Act
  ConverterNumbersInWords converter(number);

  // Assert
  EXPECT_EQ(number, converter.GetNumber());
}

TEST_F(ConverterNumbersInWordsTest, Can_Set_Number) {
  // Arrange
  ConverterNumbersInWords converter;
  double number = 123.0;

  // Act
  converter.SetNumber(number);

  // Assert
  EXPECT_NEAR(number, converter.GetNumber(),
    ConverterNumbersInWordsTest::epsilon);
}

TEST_F(ConverterNumbersInWordsTest, Can_Get_Number) {
  // Arrange
  ConverterNumbersInWords converter(123.0);

  // Act
  double number = converter.GetNumber();

  // Assert
  EXPECT_NEAR(123.0, number, ConverterNumbersInWordsTest::epsilon);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Zero_To_Word) {
  // Arrange
  ConverterNumbersInWords converter(0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("zero", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_One_Elementary_Digit_To_Word) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(6.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("six", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Number_From_10_to_19) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(17.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("seventeen", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Round_Number_From_20_to_99) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(50.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("fifty", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_20_to_99) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(45.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("forty five", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Round_Number_From_100_to_999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(500.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("five hundred", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_100_to_999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(468.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("four hundred and sixty eight", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_1000_to_9999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(5458.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("five thousand four hundred and fifty eight", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Thousand_To_Word) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(5000.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("five thousand", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Million_To_Word) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(2000000.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("two million", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_9999_to_99999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(76390.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("seventy six thousand three hundred and ninety", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_99999_to_999999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(506800.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("five hundred and six thousand eight hundred", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Number_From_999999_to_9999999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(4300852.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("four million three hundred thousand eight hundred and fifty two",
    result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_9999999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(200305084.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("two hundred million three hundred and five thousand eighty four",
    result);
}

TEST_F(ConverterNumbersInWordsTest, No_Throw_When_Large_Number) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(9999999991.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("number is too large for our converter", result);
}

