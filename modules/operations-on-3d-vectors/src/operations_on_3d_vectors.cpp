// Copyright 2018 Gracheva Elena

#include "include/operations_on_3d_vectors.h"
#include <cmath>

double OperationsOn3dVectors::GetNorm(const Vector3d& vector) {
    return sqrt(OperationsOn3dVectors::ScalarProduct(vector, vector));
}

double OperationsOn3dVectors::ScalarProduct(const Vector3d& vector1, const Vector3d& vector2) {
    return vector1.GetComponent(0) * vector2.GetComponent(0) + 
        vector1.GetComponent(1) * vector2.GetComponent(1) + 
        vector1.GetComponent(2) * vector2.GetComponent(2);
}

Vector3d OperationsOn3dVectors::VectorProduct(const Vector3d& vector1, const Vector3d& vector2) {
    Vector3d result;
    result[0] = vector1.GetComponent(1)*vector2.GetComponent(2) - vector1.GetComponent(2)*vector2.GetComponent(1);
    result[1] = vector1.GetComponent(2)*vector2.GetComponent(0) - vector1.GetComponent(0)*vector2.GetComponent(2);
    result[2] = vector1.GetComponent(0)*vector2.GetComponent(1) - vector1.GetComponent(1)*vector2.GetComponent(0);
    return result;
}

Vector3d OperationsOn3dVectors::GetNormalizedVector(const Vector3d& vector) {
    Vector3d result=vector;
    result[0] /= GetNorm(vector);
    result[1] /= GetNorm(vector);
    result[2] /= GetNorm(vector);
    return result;
}
