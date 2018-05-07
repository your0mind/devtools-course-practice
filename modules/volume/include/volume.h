// Copyright 2018 Shurygin Dmitriy


#ifndef MODULES_VOLUME_INCLUDE_VOLUME_H_
#define MODULES_VOLUME_INCLUDE_VOLUME_H_

class Sphere {
 private:
    double R;

 public:
    Sphere(const Sphere& sphere);
    explicit Sphere(const double _R);
    Sphere();
    double getR() const;
    void setR(const double _R);
    double Volume();
};

class Cube {
 private:
    double A;

 public:
    Cube(const Cube& cube);
    explicit Cube(const double _A);
    Cube();
    double getA() const;
    void setA(const double _A);
    double Volume();
};

class Cylinder {
 private:
    double R;
    double h;

 public:
    Cylinder(const Cylinder& cylinder);
    Cylinder(const double _R, const double _h);
    Cylinder();
    double getR() const;
    double geth() const;
    void setR(const double _R);
    void seth(const double _h);
    double Volume();
};

#endif  // MODULES_VOLUME_INCLUDE_VOLUME_H_
