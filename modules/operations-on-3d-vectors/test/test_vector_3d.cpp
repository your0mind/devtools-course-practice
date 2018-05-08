// Copyright 2018 Gracheva Elena

#include <gtest/gtest.h>
#include "include/vector_3d.h"

TEST(Gracheva_Elena_TestVector3d, correct_constructor_with_parameters) {
    // Arrange
    double component0 = 1, component1 = 2, component2 = 3;

    // Act
    Vector3d vector(component0, component1, component2);

    // Assert
    EXPECT_DOUBLE_EQ(component0, vector.GetComponent(0));
    EXPECT_DOUBLE_EQ(component1, vector.GetComponent(1));
    EXPECT_DOUBLE_EQ(component2, vector.GetComponent(2));
}

TEST(Gracheva_Elena_TestVector3d, can_create_zero_vector) {
    // Arrange
    Vector3d expectedResult(0, 0, 0);

    // Act
    Vector3d result;

    // Assert
    EXPECT_EQ(expectedResult, result);
}

TEST(Gracheva_Elena_TestVector3d, can_get_component) {
    // Arrange
    Vector3d vector(1, 2, 3);

    // Act
    double data1 = vector.GetComponent(1);

    // Assert
    EXPECT_DOUBLE_EQ(2, data1);
}

TEST(Gracheva_Elena_TestVector3d, can_set_component) {
    // Arrange
    Vector3d vector(1, 2, 3);
    double setValue = 1;

    // Act
    vector.SetComponent(2, setValue);

    // Assert
    EXPECT_DOUBLE_EQ(setValue, vector.GetComponent(2));
}

TEST(Gracheva_Elena_TestVector3d,
    cant_set_component_if_index_less_than_0) {
    // Arrange
    Vector3d vector(1, 2, 3);

    // Act

    // Assert
    EXPECT_ANY_THROW(vector.SetComponent(-1, 1));
}

TEST(Gracheva_Elena_TestVector3d,
    cant_set_component_if_index_more_than_2) {
    // Arrange
    Vector3d vector(1, 2, 3);

    // Act, Assert
    EXPECT_ANY_THROW(vector.SetComponent(3, 1));
}

TEST(Gracheva_Elena_TestVector3d,
    cant_get_component_if_index_less_than_0) {
    // Arrange
    Vector3d vector(1, 2, 3);

    // Act

    // Assert
    EXPECT_ANY_THROW(vector.GetComponent(-1));
}

TEST(Gracheva_Elena_TestVector3d,
    cant_get_component_if_index_more_than_2) {
    // Arrange
    Vector3d vector(1, 2, 3);

    // Act, Assert
    EXPECT_ANY_THROW(vector.GetComponent(3));
}

TEST(Gracheva_Elena_TestVector3d, can_compare_equals_vector) {
    // Arrange
    Vector3d vector1(1, 2, 3), vector2(1, 2, 3);

    // Act

    // Assert
    EXPECT_TRUE(vector1 == vector2);
}

TEST(Gracheva_Elena_TestVector3d, can_compare_not_equals_vector) {
    // Arrange
    Vector3d vector1(1, 2, 3), vector2(1, 2, 4);

    // Act

    // Assert
    EXPECT_TRUE(vector1 != vector2);
}
