// Copyright 2018 Gracheva Elena

#include "include/vector_3d.h"
#include <stdexcept>

Vector3d::Vector3d() {
    data[0] = data[1] = data[2] = 0;
}

Vector3d::Vector3d(double component0, double component1, double component2) {
    data[0] = component0;
    data[1] = component1;
    data[2] = component2;
}

double& Vector3d::operator[](int index) {
    if (index < 0 || index>2)
        throw std::invalid_argument("incorrect index");
    return data[index];
}

double Vector3d::GetComponent(int index) const {
    if (index < 0 || index>2)
        throw std::invalid_argument("incorrect index");
    return data[index];
}

bool operator==(const Vector3d & vector1, const Vector3d & vector2) {
    return (vector1.data[0]== vector2.data[0]) &&
        (vector1.data[1] == vector2.data[1]) &&
        (vector1.data[2] == vector2.data[2]);
}

bool operator!=(const Vector3d & vector1, const Vector3d & vector2) {
    return !(vector1 == vector2);
}

