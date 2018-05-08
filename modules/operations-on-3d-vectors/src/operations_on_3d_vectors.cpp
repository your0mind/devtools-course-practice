// Copyright 2018 Gracheva Elena

#include "include/operations_on_3d_vectors.h"
#include <cmath>

double OperationsOn3dVectors::GetNorm(const Vector3d& vector) {
    return sqrt(OperationsOn3dVectors::DotProduct(vector, vector));
}

double OperationsOn3dVectors::DotProduct(const Vector3d& vector1,
    const Vector3d& vector2) {
    return vector1.GetComponent(0) * vector2.GetComponent(0) +
        vector1.GetComponent(1) * vector2.GetComponent(1) +
        vector1.GetComponent(2) * vector2.GetComponent(2);
}

Vector3d OperationsOn3dVectors::CrossProduct(const Vector3d& vector1,
    const Vector3d& vector2) {
    Vector3d result;
    result.x = vector1.GetComponent(1)*vector2.GetComponent(2) -
        vector1.GetComponent(2)*vector2.GetComponent(1);
    result.y = vector1.GetComponent(2)*vector2.GetComponent(0) -
        vector1.GetComponent(0)*vector2.GetComponent(2);
    result.z = vector1.GetComponent(0)*vector2.GetComponent(1) -
        vector1.GetComponent(1)*vector2.GetComponent(0);
    return result;
}

Vector3d OperationsOn3dVectors::GetNormalizedVector(const Vector3d& vector) {
    if (GetNorm(vector) == 0)
        return vector;
    Vector3d result = vector;
    result.x /= GetNorm(vector);
    result.y /= GetNorm(vector);
    result.z /= GetNorm(vector);
    return result;
}
