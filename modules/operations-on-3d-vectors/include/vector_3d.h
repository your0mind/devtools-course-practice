#pragma once

class Vector3d {
private:
    double data[3];
public:
    Vector3d();
    Vector3d(double component1, double component2, double component3);
    
    double& operator[](int index);
    double GetComponent(int index) const;
};