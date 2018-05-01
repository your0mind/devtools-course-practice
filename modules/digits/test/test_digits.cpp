// Copyright 2018 Kozorez Alexandr

#include <gtest/gtest.h>

#include "include/Digits.h"

#include <string>

TEST(Kozorez_Alex_DigitsTest, canInitDigitClass) {
    // Arrange

    // Act

    // Assert
    ASSERT_NO_THROW(Digits Init);
}

TEST(Kozorez_Alex_DigitsTest, canGetNumberIntoArray) {
    // Arrange
    Digits Init;
    int n = 910;
    int mas[4] = { 3, 0, 1, 9 };

    // Act
    int* arr = Init.getNumberIntoArray(n);

    // Assert
    for (int i = arr[0]; i >= 1; i--)
        EXPECT_TRUE(mas[i] == arr[i]);
}

TEST(Kozorez_Alex_DigitsTest, DigitNumberIsEqualToHis) {
    // Arrange
    Digits Init;
    std::string line[3];
    int n = 910;

    // Act
    line[0] = "._. ... ._. ";
    line[1] = "|_| ..| |.| ";
    line[2] = "..| ..| |_| ";
    int* arr = Init.getNumberIntoArray(n);

    // Assert
    for (int i = 0; i < 3; i++)
        EXPECT_EQ(Init.getLineOfNumber(i, arr), line[i]);
}

TEST(Kozorez_Alex_DigitsTest, DigitFirstLineStringIsEqualToThis) {
    // Arrange
    Digits Init;
    std::string first_line[10] = 
    { "._.", "...", "._.", "._.", "...", "._.", "._.", "._.", "._.", "._." };
    int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // Act

    // Assert
    for (int i = 0; i < 10; i++)
        EXPECT_EQ(Init.getLineOfNumeral(0, arr[i]), first_line[i]);
}
