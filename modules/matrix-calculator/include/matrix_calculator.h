// Copyright 2018 Fedorova Olga

#ifndef MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_
#define MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_

#include <vector>

class MatrixCalculator {
 public:
    MatrixCalculator();
    MatrixCalculator(const int rows, const int columns);
    MatrixCalculator(const MatrixCalculator&);

    void SetMatrix(std::vector<std::vector<double>> &);

    MatrixCalculator operator +(const MatrixCalculator&) const;
    MatrixCalculator operator -(const MatrixCalculator&) const;
    MatrixCalculator operator *(const MatrixCalculator&) const;
    MatrixCalculator& operator =(const MatrixCalculator&);

    double determinant() const;
    MatrixCalculator InverseMatrix() const;

    bool operator ==(const MatrixCalculator&) const;
    bool AreSizesEqual(const MatrixCalculator&) const;

 private:
    std::vector<std::vector<double > > matrix;
    MatrixCalculator Prepare_for_minores(int,
        std::vector<std::vector<double > >, int, int) const;
    MatrixCalculator Transpon(int a) const;
};

#endif  // MODULES_MATRIX_CALCULATOR_INCLUDE_MATRIX_CALCULATOR_H_
