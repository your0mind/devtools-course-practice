// Copyright 2018 Panov Aleksander

#include <gtest/gtest.h>
#include "include/two_lines.h"

TEST(Panov_Aleksander_LinesTest, Different_Points_Not_Intersect) {
    // Arrange
    Point startLine1(0, 0), endLine1(0, 0);
    Point startLine2(1, 1), endLine2(1, 1);

    // Act
    bool isIntersect = intersect(startLine1, endLine1, startLine2, endLine2);

    // Assert
    EXPECT_FALSE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Equal_Points_Intersect) {
    // Arrange
    Point startLine1(0, 0), endLine1(0, 0);
    Point startLine2(0, 0), endLine2(0, 0);

    // Act
    bool isIntersect = intersect(startLine1, endLine1, startLine2, endLine2);

    // Assert
    EXPECT_TRUE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Simle_Intersect) {
    // Arrange
    Point startLine1(0, 0), endLine1(1, 1);
    Point startLine2(0, 1), endLine2(1, 0);

    // Act
    bool isIntersect = intersect(startLine1, endLine1, startLine2, endLine2);

    // Assert
    EXPECT_TRUE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Parallel_Lines) {
    // Arrange
    Point startLine1(0, 0), endLine1(0, 1);
    Point startLine2(0.1, 0), endLine2(0.1, 1);

    // Act
    bool isIntersect = intersect(startLine1, endLine1, startLine2, endLine2);

    // Assert
    EXPECT_FALSE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Coverage) {
    Point startLine1(0, -1), endLine1(0, 1);
    Point startLine2(0, 0.01), endLine2(0, 0.02);

    // Act
    bool isIntersect = intersect(startLine1, endLine1, startLine2, endLine2);

    // Assert
    EXPECT_TRUE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Tangent_Lines) {
    // Arrange
    Point startLine1(0, 0), endLine1(1000, 1000);
    Point startLine2(0, 1000), endLine2(500, 500);

    // Act
    bool isIntersect = intersect(startLine1, endLine1, startLine2, endLine2);

    // Assert
    EXPECT_TRUE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Not_Tangent_Lines) {
    // Arrange
    Point startLine1(0, 0), endLine1(1000, 1000);
    Point startLine2(0, 1000), endLine2(499.5, 500);

    // Act
    bool isIntersect = intersect(startLine1, endLine1, startLine2, endLine2);

    // Assert
    EXPECT_FALSE(isIntersect);
}
