// Copyright 2018 Kulikova Svetlana

#include <gtest/gtest.h>

#include "include/line_plane_intersection.h"

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, Intersect1) {
    // Arrange
    dot Line1 = { 0, 9, -11 };
    dot Line2 = { 1, 12, -14 };
    dot Plane1 = { 0, 0, 3 };
    dot Plane2 = { 0, 1, 1 };
    dot Plane3 = { -3, 0, 0 };
    dot EQ = { -2, 3, -5 };
    dot res;
    double epsilon = 1e-6;
    line_plane_intersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_NEAR(EQ.x, res.x, epsilon);
    EXPECT_NEAR(EQ.y, res.y, epsilon);
    EXPECT_NEAR(EQ.z, res.z, epsilon);
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, Intersect2) {
    // Arrange
    dot Line1 = { 0, 3, -4 };
    dot Line2 = { -3, 0, 3.5 };
    dot Plane1 = { 0, 1, 7 };
    dot Plane2 = { -1, 5, 4 };
    dot Plane3 = { -2, 3, 1 };
    dot EQ = { -2, 1, 1 };
    dot res;
    double epsilon = 1e-6;
    line_plane_intersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_NEAR(EQ.x, res.x, epsilon);
    EXPECT_NEAR(EQ.y, res.y, epsilon);
    EXPECT_NEAR(EQ.z, res.z, epsilon);
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, NotIntersect) {
    // Arrange
    dot Line1 = { 0, -2, 1 };
    dot Line2 = { 1, 0, 1 };
    dot Plane1 = { 0, 1, 0 };
    dot Plane2 = { -0.5, 0, 0 };
    dot Plane3 = { 1, 0, 1 };
    dot res;
    line_plane_intersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_TRUE(F.GetNotIntersectPlaneLine());
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectLine) {
    // Arrange
    dot Line1 = { 0, 0, 0 };
    dot Line2 = { 0, 0, 0 };
    dot Plane1 = { 0, 1, 0 };
    dot Plane2 = { -0.5, 0, 0 };
    dot Plane3 = { 1, 0, 1 };
    line_plane_intersection F;

    // Act & Assert
    EXPECT_ANY_THROW(F.PlaneIntersectLine(Plane1,
        Plane2, Plane3, Line1, Line2));
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectPlaneA) {
    // Arrange
    dot Line1 = { 0, 0, 0 };
    dot Line2 = { 0, 1, 0 };
    dot Plane1 = { 0, 0, 0 };
    dot Plane2 = { 0, 0, 0 };
    dot Plane3 = { 0, 1, 0 };
    line_plane_intersection F;

    // Act & Assert
    EXPECT_ANY_THROW(F.PlaneIntersectLine(Plane1,
        Plane2, Plane3, Line1, Line2));
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectPlaneB) {
    // Arrange
    dot Line1 = { 0, 0, 0 };
    dot Line2 = { 0, 1, 0 };
    dot Plane1 = { 0, 0, 0 };
    dot Plane2 = { 0, 1, 0 };
    dot Plane3 = { 0, 0, 0 };
    line_plane_intersection F;

    // Act & Assert
    EXPECT_ANY_THROW(F.PlaneIntersectLine(Plane1,
        Plane2, Plane3, Line1, Line2));
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectPlaneC) {
    // Arrange
    dot Line1 = { 0, 0, 0 };
    dot Line2 = { 0, 1, 0 };
    dot Plane1 = { 0, 1, 0 };
    dot Plane2 = { 0, 0, 0 };
    dot Plane3 = { 0, 0, 0 };
    dot res;
    line_plane_intersection F;

    // Act & Assert
    EXPECT_ANY_THROW(F.PlaneIntersectLine(Plane1,
        Plane2, Plane3, Line1, Line2));
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, VariableDeclaration) {
    // Act & Assert
    ASSERT_NO_THROW(dot A);
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, CopyConstractor) {
    // Arrange
    xyz A = { 0, 0, 0 };

    // Act & Assert
    ASSERT_NO_THROW(dot B(A));
}
