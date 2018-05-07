// Copyright 2018 Shurygin Dmitriy


#ifndef MODULES_VOLUME_H_
#define MODULES_VOLUME_H_

class Shape {
 public:
    virtual double Volume() = 0;
};

class Sphere : public Shape {
 private:
    double R;

 public:
    Sphere(const Sphere& sphere);
    Sphere(const double _R);
    Sphere();
    double getR() const;
    double Volume();
};

class Cube : public Shape {
 private:
    double A;

 public:
    Cube(const Cube& cube);
    Cube(const double _A);
    Cube();
    double getA() const;
    double Volume();
};

class Cylinder : public Shape {
 private:
    double R;
    double h;

 public:
    Cylinder(const Cylinder& cylinder);
    Cylinder(const double _R, const double _h);
    Cylinder();
    double getR() const;
    double geth() const;
    double Volume();
};

#endif  // MODULES_VOLUME_H_
