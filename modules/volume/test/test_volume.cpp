// Copyright 2018 Shurygin Dmitriy

#include <gtest/gtest.h>

#include "include/volume.h"

TEST(Shurygin_Dmitriy_Volume_Test, Get_Radius_From_Sphere) {
     // Arrange
    double _R = 3;
    Sphere sphere(_R);

    // Act & Assert
    EXPECT_EQ(_R, sphere.getR());
}

TEST(Shurygin_Dmitriy_Volume_Test, Get_A_From_Cube) {
    // Arrange
    double _A = 2.4;
    Cube cube(_A);

    // Act & Assert
    EXPECT_EQ(_A, cube.getA());
}

TEST(Shurygin_Dmitriy_Volume_Test, Get_R_From_Cylinder) {
    // Arrange
    double _R = 2.4;
    double _h = 1.23;
    Cylinder cylinder(_R, _h);

    // Act & Assert
    EXPECT_EQ(_R, cylinder.getR());
}

TEST(Shurygin_Dmitriy_Volume_Test, Get_h_From_Cylinder) {
    // Arrange
    double _R = 2.4;
    double _h = 1.23;
    Cylinder cylinder(_R, _h);

    // Act & Assert
    EXPECT_EQ(_h, cylinder.geth());
}

TEST(Shurygin_Dmitriy_Volume_Test, Set_R_From_Sphere) {
     // Arrange
    Sphere sphere;
    double _R = 7.4;

    // Act
    sphere.setR(_R);

    // Assert
    EXPECT_EQ(_R, sphere.getR());
}

TEST(Shurygin_Dmitriy_Volume_Test, Volume_Calculation_Cube) {
    // Arrange
    double res = 0;
    Cube cube(2.0);

    // Act
    res = cube.Volume();

    // Assert
    EXPECT_NEAR(res, 8.0, 0.0001);
}
