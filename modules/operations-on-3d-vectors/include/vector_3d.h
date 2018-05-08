// Copyright 2018 Gracheva Elena

#ifndef MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_VECTOR_3D_H_
#define MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_VECTOR_3D_H_

class Vector3d {
 private:
     double x;
     double y;
     double z;
 public:
    Vector3d();
    Vector3d(double component0, double component1, double component2);

    void SetComponent(int index, double value);
    double GetComponent(int index) const;

    friend bool operator==(const Vector3d& vector1, const Vector3d& vector2);
    friend bool operator!=(const Vector3d& vector1, const Vector3d& vector2);

    friend class OperationsOn3dVectors;
};

#endif  // MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_VECTOR_3D_H_
