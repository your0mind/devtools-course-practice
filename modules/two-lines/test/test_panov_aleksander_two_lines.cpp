// Copyright 2018 Panov Aleksander

#include <gtest/gtest.h>
#include "include/two_lines.h"

TEST(Panov_Aleksander_LinesTest, Can_Create_Point) {
    // Arrange
    double x = 0.0;
    double y = 0.0;

    // Act
    Line p(x, y);

    // Assert
    EXPECT_EQ(x, p.getX());
    EXPECT_EQ(y, p.getY());
}

TEST(Panov_Aleksander_LinesTest, Can_Create_Copy) {
    // Arrange
    double x = 1.0;
    double y = -1.0;
    Line p1(x, y);

    // Act
    Line p2(p1);

    // Assert
    EXPECT_EQ(p1, p2);
}