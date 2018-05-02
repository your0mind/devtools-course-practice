//Copyright 2018 Gracheva Elena

#pragma once

class Vector3d {
private:
    double data[3];
public:
    Vector3d();
    Vector3d(double component0, double component1, double component2);
    
    double& operator[](int index);
    double GetComponent(int index) const;

    friend bool operator==(const Vector3d& vector1, const Vector3d& vector2);
    friend bool operator!=(const Vector3d& vector1, const Vector3d& vector2);
};