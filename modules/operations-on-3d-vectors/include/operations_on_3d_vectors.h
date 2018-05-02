//Copyright 2018 Gracheva Elena

#pragma once
#include "vector_3d.h"

class OperationsOn3dVectors {
public:
    static double GetNorm(const Vector3d& vector);
    static double ScalarProduct(const Vector3d& vector1, const Vector3d& vector2);
    static Vector3d VectorProduct(const Vector3d& vector1, const Vector3d& vector2);
    static Vector3d GetNormalizedVector(const Vector3d& vector);
};
