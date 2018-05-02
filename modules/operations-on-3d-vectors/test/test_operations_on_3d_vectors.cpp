#include <gtest/gtest.h>
#include "operations_on_3d_vectors.h"
#include "vector_3d.h"

TEST(TestOperationsOn3dVectors, get_correct_norm) {
    // Arrange
    Vector3d vector(0, 3, -4);

    // Act
    double result = OperationsOn3dVector::GetNorm(vector);

    // Assert
    EXPECT_DOUBLE_EQ(5, result);
}

TEST(TestOperationsOn3dVectors, get_correct_normalized_vector) {
    // Arrange
    Vector3d vector(0, 3, -4);
    Vector3d expectedResult(0, 3 / 5, -4 / 5);

    // Act
    Vector3d result = OperationsOn3dVector::GetNormalizedVector(vector);

    // Assert
    EXPECT_EQ(expectedResult, result);
}

TEST(TestOperationsOn3dVectors, get_correct_scalar_product) {
    // Arrange
    Vector3d vector1(1, 2, 3), vector2(2, 3, -4);

    // Act
    double result = OperationsOn3dVector::ScalarProduct(vector1, vector2);

    // Assert
    EXPECT_DOUBLE_EQ(-4, result);
}

TEST(TestOperationsOn3dVectors, get_correct_vector_product) {
    // Arrange
    Vector3d vector1(0, 1, 0), vector2(1, 0, 0);
    Vector3d expectedResult(0, 0, -1);

    // Act
    Vector3d result = OperationsOn3dVector::VectorProduct(vector1, vector2);

    // Assert
    EXPECT_EQ(expectedResult, result);
}