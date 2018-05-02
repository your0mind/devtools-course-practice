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

TEST(Panov_Aleksander_LinesTest, Can_Detect_Parallel_Lines)
{
    Point a, b(0, 1);
    Point c(0.1, 0), d(0.1, 1);

    // Act
    bool isIntersect = intersect(a, b, c, d);

    // Assert
    EXPECT_FALSE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Coverage)
{
    Point a(0, -1), b(0, 1);
    Point c(0, 0.01), d(0, 0.02);

    // Act
    bool isIntersect = intersect(a, b, c, d);

    // Assert
    EXPECT_TRUE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Tangent) {
    // Arrange
    Point a(0, 0), b(1000, 1000);
    Point c(0, 1000), d(500, 500);

    // Act
    bool isIntersect = intersect(a, b, c, d);

    // Assert
    EXPECT_TRUE(isIntersect);
}