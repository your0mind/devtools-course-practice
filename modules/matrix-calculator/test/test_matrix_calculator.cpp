// Copyright 2018 Fedorova Olga

#include <gtest/gtest.h>
#include <vector>
#include "include/matrix_calculator.h"

TEST(MatrixCalculatorTest, can_create_default_and_with_sizes) {
    MatrixCalculator a;
    MatrixCalculator b(1, 1);

    EXPECT_EQ(a, b);
}

TEST(MatrixCalculatorTest, can_create_copy) {
    MatrixCalculator a(2, 2);
    MatrixCalculator b(a);

    EXPECT_EQ(a, b);
}

TEST(MatrixCalculatorTest, cant_create_with_negativ_sizes) {
    EXPECT_ANY_THROW(MatrixCalculator matrix(-1, -1));
}

TEST(MatrixCalculatorTest, correct_set) {
    std::vector<std::vector<double>> vect(3, std::vector<double>(3, 0.0));
    for (size_t i = 0; i < vect.size(); i++) {
        vect[i][i] = 3;
    }
    MatrixCalculator a(1, 2);
    MatrixCalculator b(a);

    a.SetMatrix(vect);
    b.SetMatrix(vect);

    EXPECT_EQ(a, b);
}

TEST(MatrixCalculatorTest, size_error_in_set) {
    std::vector<std::vector<double>> vect(2);
    vect[0] = std::vector<double>(1);
    vect[1] = std::vector<double>(3);

    MatrixCalculator a;

    EXPECT_ANY_THROW(a.SetMatrix(vect));
}

TEST(MatrixCalculatorTest, correct_are_sizes_equal) {
    std::vector<std::vector<double>> vect1(3, std::vector<double>(3, 0.0));
    std::vector<std::vector<double>> vect2(3, std::vector<double>(5, 0.0));

    MatrixCalculator a;
    MatrixCalculator b;
    a.SetMatrix(vect1);
    b.SetMatrix(vect2);

    EXPECT_FALSE(a.AreSizesEqual(b));
}

TEST(MatrixCalculatorTest, correct_equal_operator) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(2, std::vector<double>(2, 2));

    MatrixCalculator a, b;
    a.SetMatrix(vect1);
    b.SetMatrix(vect2);

    a = b;

    EXPECT_EQ(a, b);
}

TEST(MatrixCalculatorTest, correct_plus_operator) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(1, std::vector<double>(1, 2));
    std::vector<std::vector<double>> vect3(1, std::vector<double>(1, 3));

    MatrixCalculator a, b, sum, real_res;
    a.SetMatrix(vect1);
    b.SetMatrix(vect2);
    real_res.SetMatrix(vect3);

    sum = a + b;

    EXPECT_EQ(sum, real_res);
}

TEST(MatrixCalculatorTest, correct_minus_operator) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(1, std::vector<double>(1, 2));
    std::vector<std::vector<double>> vect3(1, std::vector<double>(1, -1));

    MatrixCalculator a, b, res, real_res;
    a.SetMatrix(vect1);
    b.SetMatrix(vect2);
    real_res.SetMatrix(vect3);

    res = a - b;

    EXPECT_EQ(res, real_res);
}

TEST(MatrixCalculatorTest, correct_multiply_operator) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(1, std::vector<double>(1, 2));
    std::vector<std::vector<double>> vect3(1, std::vector<double>(1, 2));

    MatrixCalculator a, b, res, real_res;
    a.SetMatrix(vect1);
    b.SetMatrix(vect2);
    real_res.SetMatrix(vect3);

    res = a * b;

    EXPECT_EQ(res, real_res);
}

TEST(MatrixCalculatorTest, operator_plus_error_with_not_equal_size) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(1, std::vector<double>(2, 2));

    MatrixCalculator a, b;
    a.SetMatrix(vect1);
    b.SetMatrix(vect2);

    EXPECT_ANY_THROW(a + b);
}

TEST(MatrixCalculatorTest, operator_minus_error_with_not_equal_size) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(1, 1));
    std::vector<std::vector<double>> vect2(1, std::vector<double>(2, 2));

    MatrixCalculator a, b;
    a.SetMatrix(vect1);
    b.SetMatrix(vect2);

    EXPECT_ANY_THROW(a - b);
}

TEST(MatrixCalculatorTest, operator_multiply_error_with_wrong_size) {
    std::vector<std::vector<double>> vect1(1, std::vector<double>(2, 1));
    std::vector<std::vector<double>> vect2(3, std::vector<double>(2, 2));

    MatrixCalculator a, b;
    a.SetMatrix(vect1);
    b.SetMatrix(vect2);

    EXPECT_ANY_THROW(a * b);
}

TEST(MatrixCalculatorTest, correct_determinant) {
    std::vector<std::vector<double>> vect = {
    { 1, 2 },
    { 3, 4 } };
    double real_res = -2;

    MatrixCalculator a;
    a.SetMatrix(vect);

    EXPECT_EQ(a.determinant(), real_res);
}

TEST(MatrixCalculatorTest, determinant_error_with_not_square_matrix) {
    std::vector<std::vector<double>> vect = {
    { 1, 2 },
    { 1, 3 },
    { 3, 4 } };

    MatrixCalculator a;
    a.SetMatrix(vect);

    EXPECT_ANY_THROW(a.determinant());
}

TEST(MatrixCalculatorTest, inverse_error_with_not_square_matrix) {
    std::vector<std::vector<double>> vect = {
    { 1, 2 },
    { 1, 3 },
    { 3, 4 } };

    MatrixCalculator a;
    a.SetMatrix(vect);

    EXPECT_ANY_THROW(a.InverseMatrix());
}

TEST(MatrixCalculatorTest, inverse_error_with_zero_determinant) {
    std::vector<std::vector<double>> vect = {
    { 1, 2 },
    { 1, 2 } };

    MatrixCalculator a;
    a.SetMatrix(vect);

    EXPECT_ANY_THROW(a.InverseMatrix());
}

TEST(MatrixCalculatorTest, correct_inverse) {
    std::vector<std::vector<double>> vect1 = {
    { 1, 2 },
    { 1, 3 } };
    std::vector<std::vector<double>> vect2 = {
    { 3, -2 },
    { -1, 1 } };

    MatrixCalculator a, real_res;
    a.SetMatrix(vect1);
    real_res.SetMatrix(vect2);

    EXPECT_EQ(a.InverseMatrix(), real_res);
}
