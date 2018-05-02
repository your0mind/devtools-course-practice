// Copyright 2018 Panov Aleksander

#include <gtest/gtest.h>
#include "include/two_lines.h"

TEST(Panov_Aleksander_LinesTest, Different_Points_Not_Intersect) {
    // Arrange
    Point a(0, 0), b(1, 1);
    // Act
    bool isIntersect = intersect(a, a, b, b);

    // Assert
    EXPECT_FALSE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Equal_Points_Intersect) {
    // Arrange
    Point a(0, 0);
    // Act
    bool isIntersect = intersect(a, a, a, a);

    // Assert
    EXPECT_TRUE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Simle_Intersect) {
    // Arrange
    Point a, b(1,1);
    Point c(0, 1), d(1, 0);

    // Act
    bool isIntersect = intersect(a, b, c, d);

    // Assert
    EXPECT_TRUE(isIntersect);
}