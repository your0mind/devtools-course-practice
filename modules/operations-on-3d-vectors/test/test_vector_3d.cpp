#include <gtest/gtest.h>
#include "vector_3d.h"

TEST(TestVector3d, correct_constructor_with_parameters) {
    // Arrange
    double component0 = 1, component1 = 2, component2 = 3;

    // Act
    Vector3d vector(component0, component1, component2);

    // Assert
    EXPECT_DOUBLE_EQ(component0, vector.GetComponent(0));
    EXPECT_DOUBLE_EQ(component1, vector.GetComponent(1));
    EXPECT_DOUBLE_EQ(component2, vector.GetComponent(2));
}

TEST(TestVector3d, correct_constructor_without_parameters) {
    // Arrange
    Vector3d expectedResult(0, 0, 0);

    // Act
    Vector3d result;

    // Assert
    EXPECT_EQ(expectedResult, result);
}

TEST(TestVector3d, correct_indexing_valid_arguments) {
    // Arrange
    Vector3d vector(1, 2, 3);

    // Act
    double data1=vector[1];

    // Assert
    EXPECT_DOUBLE_EQ(2, data1);
}

TEST(TestVector3d, get_correct_component_valid_arguments) {
    // Arrange
    Vector3d vector(1, 2, 3);

    // Act
    double data1 = vector.GetComponent(1);

    // Assert
    EXPECT_DOUBLE_EQ(2, data1);
}

TEST(TestVector3d, correct_indexing_invalid_arguments) {
    // Arrange
    Vector3d vector(1, 2, 3);

    // Act, Assert
    EXPECT_ANY_THROW(vector[3]);
}

TEST(TestVector3d, get_correct_component_invalid_arguments) {
    // Arrange
    Vector3d vector(1, 2, 3);

    // Act, Assert
    EXPECT_ANY_THROW(vector.GetComponent(-1));
}