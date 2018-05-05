// Copyright 2018 Boris Ermachenko
#include <gtest/gtest.h>
//#include "include/temperature_converter.h"
#include "include/Calculation_Rent.h"

TEST(Calculation_Rent_Test, Can_Create_Object){
    // Assert
    ASSERT_NO_THROW(Calculation_Rent rent_tmp);
    
}

TEST(Calculation_Rent_Test, Can_Calculate_Rent_Accumulated_Yearly_postnumerando_with_hard_rate){
    // Arrange
    Calculation_Rent rent;
    // Act
    double result = rent.Rent_Accumulated_Yearly_postnumerando_with_hard_rate(50, 2, 3);

         // Assert
        EXPECT_EQ(250, result);
    
}

TEST(Calculation_Rent_Test, Can_Calculate_Rent_Accumulated_Yearly_postnumerando_with_easy_rate){
    // Arrange
    Calculation_Rent rent;

    // Act
    double result = rent.Rent_Accumulated_Yearly_postnumerando_with_easy_rate(150.4, 20, 10);

    // Assert
    EXPECT_EQ(288768, result);
    
}

TEST(Calculation_Rent_Tes, Can_Calculate_Rent_Accumulated_Yearly_prenumerando_with_hard_rate){
    // Arrange
    Calculation_Rent rent;

    // Act
    double result = rent.Rent_Accumulated_Yearly_prenumerando_with_hard_rate(10000, 5, 2);

    // Assert
    EXPECT_EQ(3630000, result);
    
}

TEST(Temperature_Converter_Test, Can_Calculate_Rent_Accumulated_Yearly_pretnumerando_with_easy_rate) {
    // Arrange
    Calculation_Rent rent;

    // Act
    double result = rent.Rent_Accumulated_Yearly_pretnumerando_with_easy_rate(120000, 10, 5);

    // Assert
    EXPECT_EQ(34200000, result);
    
}

TEST(Temperature_Converter_Test, Can_Calculate_Rent_Accumulated_P_Period_postnumerando) {
    // Arrange
    Calculation_Rent rent;

    // Act
    double result = rent.Rent_Accumulated_P_Period_postnumerando(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(164000, result);
    
}

TEST(Temperature_Converter_Test, Can_Calculate_Rent_Accumulated_P_Period_prenumerando){
    // Arrange
    Calculation_Rent rent;

    // Act
    double result = rent.Rent_Accumulated_P_Period_prenumerando(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(492000, result);
}

TEST(Temperature_Converter_Test, Can_Calculate_Rent_Modern_Yearly_postnumerando_with_hard_rate){
    // Arrange
    Calculation_Rent rent;

    // Act
    double result = rent.Rent_Modern_Yearly_postnumerando_with_hard_rate(7861, 8, 4);

    // Assert
    EXPECT_EQ(1965.24496896, result);
    
}

TEST(Temperature_Converter_Test, Can_Calculate_Rent_Modern_Yearly_postnumerando_with_easy_rate){
    // Arrange
    Calculation_Rent rent;

    // Act
    double result = rent.Rent_Modern_Yearly_postnumerando_with_easy_rate(10000, 2, 10);

    // Assert
    EXPECT_EQ(1385.28, result);
}

TEST(Temperature_Converter_Test, Can_Calculate_Rent_Modern_Yearly_prenumerando_with_hard_rate){
    // Arrange
    Calculation_Rent rent;

    // Act
    double result = rent.Rent_Modern_Yearly_prenumerando_with_hard_rate(50, 200, 3);

    // Assert
    EXPECT_EQ(66.6667, result);
    
}

TEST(Temperature_Converter_Test, Can_Calculate_Rent_Modern_Yearly_pretnumerando_with_easy_rate){
    // Arrange
    Calculation_Rent rent;

    // Act
    double result = rent.Rent_Modern_Yearly_pretnumerando_with_easy_rate(50, 2, 30000);

    // Assert
    EXPECT_EQ(50, result);
}

TEST(Temperature_Converter_Test, Can_Calculate_Rent_Modern_P_Period_postnumerando){
    // Arrange
    Calculation_Rent rent;

    // Act
    double result = rent.Rent_Modern_P_Period_postnumerando(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(24.9962, result);
}

TEST(Temperature_Converter_Test, Can_Calculate_Rent_Modern_P_Period_prenumerando){
    // Arrange
    Calculation_Rent rent;

    // Act
    double result = rent.Rent_Modern_P_Period_prenumerando(100, 4, 5, 2, 2);

    // Assert
    EXPECT_EQ(74.9886, result);
}

TEST(Calculation_Rent_Test, Cant_Calculate_Rent_Accumulated_Yearly_postnumerando_with_hard_rate_With_wrong_parametres){
    // Arrange
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Accumulated_Yearly_postnumerando_with_hard_rate(0,-1,6));
}

TEST(Calculation_Rent_Test, Cant_Calculate_Rent_Accumulated_Yearly_postnumerando_with_easy_rate_With_wrong_parametres){
    // Arrange
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Accumulated_Yearly_postnumerando_with_easy_rate(0, -1, 0));
}

TEST(Calculation_Rent_Tes, Cant_Calculate_Rent_Accumulated_Yearly_prenumerando_with_hard_rate_With_wrong_parametres){
    // Arrange
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Accumulated_Yearly_prenumerando_with_hard_rate(0, 0, 2));

}

TEST(Temperature_Converter_Test, Cant_Calculate_Rent_Accumulated_Yearly_pretnumerando_with_easy_rate_With_wrong_parametres){
    // Arrange
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Accumulated_Yearly_pretnumerando_with_easy_rate(12000000000000000, 10, 5));
}

TEST(Temperature_Converter_Test, Cant_Calculate_Rent_Accumulated_P_Period_postnumerando_With_wrong_parametres){
    // Arrange
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Accumulated_P_Period_postnumerando(0, 0, 0, 0, 0));

}

TEST(Temperature_Converter_Test, Cant_Calculate_Rent_Accumulated_P_Period_prenumerando_With_wrong_parametres){
    // Arrange
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Accumulated_P_Period_prenumerando(100, 4, 5, 2, 2000000000000000000));
}

TEST(Temperature_Converter_Test, Cant_Calculate_Rent_Modern_Yearly_postnumerando_with_hard_rate_With_wrong_parametres){
    // Arrang
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Modern_Yearly_postnumerando_with_hard_rate(-7861, 8, 4));

}

TEST(Temperature_Converter_Test, Cant_Calculate_Rent_Modern_Yearly_postnumerando_with_easy_rate_With_wrong_parametres){
    // Arrange
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Modern_Yearly_postnumerando_with_easy_rate(0, 0, 0));

}

TEST(Temperature_Converter_Test, Cant_Calculate_Rent_Modern_Yearly_prenumerando_with_hard_rate_With_wrong_parametres){
    // Arrange
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Modern_Yearly_prenumerando_with_hard_rate(50, -200, 3));

}

TEST(Temperature_Converter_Test, Cant_Calculate_Rent_Modern_Yearly_pretnumerando_with_easy_rate_With_wrong_parametres){
    // Arrange
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Modern_Yearly_pretnumerando_with_easy_rate(50000000000000000, 2, 30000));

}

TEST(Temperature_Converter_Test, Cant_Calculate_Rent_Modern_P_Period_postnumerando_With_wrong_parametres){
    // Arrange
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Modern_P_Period_postnumerando(100, -4, -5, 2, 2));

}

TEST(Temperature_Converter_Test, Cant_Calculate_Rent_Modern_P_Period_prenumerando_With_wrong_parametres){
    // Arrange
    Calculation_Rent rent;

    // Act

    // Assert
    ASSERT_ANY_THROW(rent.Rent_Modern_P_Period_prenumerando(0, 4, 5, 2, 2));
}

