#include "vector_3d.h"
#include <stdexcept>

Vector3d::Vector3d() {
    data[0] = data[1] = data[2] = 0;
}

Vector3d::Vector3d(double component1, double component2, double component3) {
    data[0] = component1;
    data[1] = component2;
    data[2] = component3;
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