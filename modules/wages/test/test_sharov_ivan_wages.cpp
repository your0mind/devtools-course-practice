// Copyright 2018 Sharov Ivan

#include <gtest/gtest.h>
#include <cstdlib>
#include "include/Wages.h"


TEST(Sharov_Ivan_WagesTest, Calling_An_Empty_Constructor) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 0;
    double overtime_hours = 0;
    char* month = const_cast<char*>("January");

    // Act
    Wages ivan;

    // Assert
    EXPECT_TRUE(ivan.getSalary() == oklad);
    EXPECT_TRUE(ivan.getAdministrativeLeaveHours() == admin_hours);
    EXPECT_TRUE(ivan.getOvertime() == overtime_hours);
    EXPECT_TRUE(!strcmp(ivan.getMonth(), month));
}

TEST(Sharov_Ivan_WagesTest, Calling_The_Constructor_With_Parameters) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 0;
    double overtime_hours = 0;
    char *month = const_cast<char*>("January");

    // Act
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Assert
    EXPECT_TRUE(ivan.getSalary() == oklad);
    EXPECT_TRUE(ivan.getAdministrativeLeaveHours() == admin_hours);
    EXPECT_TRUE(ivan.getOvertime() == overtime_hours);
    EXPECT_TRUE(!strcmp(ivan.getMonth(), month));
}

TEST(Sharov_Ivan_WagesTest, Create_Copy) {
    // Arrange
    Wages ivan;

    // Act
    Wages sergey(ivan);

    // Assert
    EXPECT_TRUE(ivan.getSalary() == sergey.getSalary());
    EXPECT_TRUE(ivan.getAdministrativeLeaveHours() ==
        sergey.getAdministrativeLeaveHours());
    EXPECT_TRUE(ivan.getOvertime() == sergey.getOvertime());
    EXPECT_TRUE(!strcmp(ivan.getMonth(), sergey.getMonth()));
}

TEST(Sharov_Ivan_WagesTest, Get_Salary) {
    // Arrange
    Wages ivan;
    double oklad = 10000;

    // Act & assert
    EXPECT_TRUE(ivan.getSalary() == oklad);
}

TEST(Sharov_Ivan_WagesTest, Get_Administrative_Leave_Hours) {
    // Arrange
    Wages ivan;
    double admin_hours = 0;

    // Act & assert
    EXPECT_TRUE(ivan.getAdministrativeLeaveHours() == admin_hours);
}

TEST(Sharov_Ivan_WagesTest, Get_Overtime_Hours) {
    // Arrange
    Wages ivan;
    double overtime_hours = 0;

    // Act & assert
    EXPECT_TRUE(ivan.getOvertime() == overtime_hours);
}

TEST(Sharov_Ivan_WagesTest, Get_Month) {
    // Arrange
    Wages ivan;
    char *month = const_cast<char*>("January");

    // Act & assert
    EXPECT_TRUE(!strcmp(ivan.getMonth(), month));
}

TEST(Sharov_Ivan_WagesTest, Set_Salary) {
    // Arrange
    Wages ivan;
    double oklad = 20000;

    // Act
    ivan.setSalary(oklad);

    // Assert
    EXPECT_TRUE(ivan.getSalary() == oklad);
}

TEST(Sharov_Ivan_WagesTest, Set_Administrative_Leave_Hours) {
    // Arrange
    Wages ivan;
    double admin_hours = 10;

    // Act
    ivan.setAdministrativeLeaveHours(admin_hours);

    // Assert
    EXPECT_TRUE(ivan.getAdministrativeLeaveHours() == admin_hours);
}

TEST(Sharov_Ivan_WagesTest, Set_Overtime_Hours) {
    // Arrange
    Wages ivan;
    double overtime_hours = 20;

    // Act
    ivan.setOvertime(overtime_hours);

    // Assert
    EXPECT_TRUE(ivan.getOvertime() == overtime_hours);
}

TEST(Sharov_Ivan_WagesTest, Set_Month) {
    // Arrange
    Wages ivan;
    char *month = const_cast<char*>("Semtember");

    // Act
    ivan.setMonth(month);

    // Assert
    EXPECT_TRUE(!strcmp(ivan.getMonth(), month));
}


TEST(Sharov_Ivan_WagesTest, Control_MROT) {
    // Arrange
    Wages ivan;
    double salary = 10000;

    // Act & assert
    EXPECT_TRUE(ivan.controlMROT(salary) == true);
}

TEST(Sharov_Ivan_WagesTest, Control_Field) {
    // Arrange
    Wages ivan;
    double hours = 10;

    // Act & assert
    EXPECT_TRUE(ivan.controlField(hours) == true);
}

TEST(Sharov_Ivan_WagesTest, Control_Month) {
    // Arrange
    Wages ivan;
    char *month = const_cast<char*>("June");

    // Act & assert
    EXPECT_TRUE(ivan.controlMonth(month) == true);
}

TEST(Sharov_Ivan_WagesTest, Control_Overtime) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 1;
    double overtime_hours = 3;
    char *month = const_cast<char*>("May");
    double countWorkingDays = 20;
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    ASSERT_NO_THROW(ivan.controlOvertime(overtime_hours));
}

TEST(Sharov_Ivan_WagesTest, Control_Administrative_Leave_Hours) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 10;
    double overtime_hours = 3;
    char *month = const_cast<char*>("May");
    double countWorkingDays = 20;
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    ASSERT_NO_THROW(ivan.controlAdministrativeLeaveHours(admin_hours));
}

TEST(Sharov_Ivan_WagesTest, Get_Number_Of_Working_Days_In_May) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 1;
    double overtime_hours = 3;
    char *month = const_cast<char*>("May");
    double countWorkingDays = 20;
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    EXPECT_TRUE(ivan.getNumberWorkingDaysInCurrentMonth() == countWorkingDays);
}

TEST(Sharov_Ivan_WagesTest, Calculation_Payment_Overtime_10_hours_In_May) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 5;
    double overtime_hours = 10;
    char *month = const_cast<char*>("May");
    double payment_Overtime_10_hours = 1187.5;
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    EXPECT_TRUE(ivan.calculationPaymentOvertime() == payment_Overtime_10_hours);
}

TEST(Sharov_Ivan_WagesTest, Calculation_Payment_Overtime_1_hour_In_May) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 5;
    double overtime_hours = 1;
    char *month = const_cast<char*>("May");
    double payment_Overtime_1_hour = 93.75;
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    EXPECT_TRUE(ivan.calculationPaymentOvertime() == payment_Overtime_1_hour);
}

TEST(Sharov_Ivan_WagesTest, Calculation_Payment_Overtime_0_hour_In_May) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 5;
    double overtime_hours = 0;
    char *month = const_cast<char*>("May");
    double payment_Overtime_0_hour = 0;
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    EXPECT_TRUE(ivan.calculationPaymentOvertime() == payment_Overtime_0_hour);
}

TEST(Sharov_Ivan_WagesTest, Calculation_Actual_Working_Days_In_December) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 8;
    double overtime_hours = 5;
    char *month = const_cast<char*>("December");
    double workDays = 20;
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    EXPECT_TRUE(ivan.calculationActualWorkingDays() == workDays);
}

TEST(Sharov_Ivan_WagesTest,
    Calculation_Actual_Working_Days_In_April_Without_Adm_Hours_And_Overtime) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 0;
    double overtime_hours = 0;
    char *month = const_cast<char*>("April");
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    EXPECT_TRUE(ivan.calculationActualWorkingDays() ==
        ivan.getNumberWorkingDaysInCurrentMonth());
}

TEST(Sharov_Ivan_WagesTest,
    Calculation_Wages_Without_Overtime_With_Admin_Hours_0_In_October) {
    // Arrange
    double oklad = 21000;
    double admin_hours = 0;
    double overtime_hours = 0;
    char *month = const_cast<char*>("October");
    double wages = 21000;
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    EXPECT_TRUE(ivan.calculationWagesWithoutOvertime() == wages);
}

TEST(Sharov_Ivan_WagesTest,
    Calculation_Wages_Without_Overtime_With_Admin_Hours_24_In_November) {
    // Arrange
    double oklad = 21000;
    double admin_hours = 24;
    double overtime_hours = 8;
    char *month = const_cast<char*>("November");
    double wages = 18000;
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    EXPECT_TRUE(ivan.calculationWagesWithoutOvertime() == wages);
}

TEST(Sharov_Ivan_WagesTest, Calculation_Full_Wages) {
    // Arrange
    double oklad = 21000;
    double admin_hours = 24;
    double overtime_hours = 8;
    char *month = const_cast<char*>("November");
    double wages = 18000;
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    EXPECT_TRUE(ivan.calculationWagesWithoutOvertime() == wages);
}

TEST(Sharov_Ivan_WagesTest,
    Calculation_Full_Wages_Without_Overtime_And_Administrative_Leave) {
    // Arrange
    double oklad = 21000;
    double admin_hours = 0;
    double overtime_hours = 0;
    char *month = const_cast<char*>("November");
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    EXPECT_TRUE(ivan.calculationFullWages() ==
        ivan.calculationWagesWithoutOvertime());
}

TEST(Sharov_Ivan_WagesTest, Input_Salary_Less_Than_Minimum_Wage) {
    // Arrange
    double oklad = 2100;
    double admin_hours = 24;
    double overtime_hours = 8;
    char *month = const_cast<char*>("November");

    // Act & assert
    ASSERT_ANY_THROW(Wages ivan(oklad, admin_hours, overtime_hours, month));
}

TEST(Sharov_Ivan_WagesTest, Input_Negative_Administrative_Leave) {
    // Arrange
    double oklad = 100000;
    double admin_hours = -24;
    double overtime_hours = 8;
    char *month = const_cast<char*>("November");

    // Act & assert
    ASSERT_ANY_THROW(Wages ivan(oklad, admin_hours, overtime_hours, month));
}

TEST(Sharov_Ivan_WagesTest, Input_Negative_Overtime) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 24;
    double overtime_hours = -8;
    char *month = const_cast<char*>("November");

    // Act & assert
    ASSERT_ANY_THROW(Wages ivan(oklad, admin_hours, overtime_hours, month));
}

TEST(Sharov_Ivan_WagesTest, Input_No_Name_Of_Month) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 24;
    double overtime_hours = 8;
    char *month = const_cast<char*>("month");

    // Act & assert
    ASSERT_ANY_THROW(Wages ivan(oklad, admin_hours, overtime_hours, month));
}

TEST(Sharov_Ivan_WagesTest, Input_Overmuch_Administrative_Leave) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 8 * 20 + 30;
    double overtime_hours = 0;
    char *month = const_cast<char*>("May");
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    ASSERT_ANY_THROW(ivan.controlAdministrativeLeaveHours(admin_hours));
}

TEST(Sharov_Ivan_WagesTest, Input_Overmuch_Overtime) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 8;
    double overtime_hours = 5 * 20;
    char *month = const_cast<char*>("May");
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    ASSERT_ANY_THROW(ivan.controlOvertime(overtime_hours));
}

TEST(Sharov_Ivan_WagesTest, Input_Overtine_In_Administrative_Leave_Month) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 8 * 20;
    double overtime_hours = 10;
    char *month = const_cast<char*>("May");
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    ASSERT_ANY_THROW(ivan.controlOvertime(overtime_hours));
}

TEST(Sharov_Ivan_WagesTest, Full_Wages_In_Administrative_Leave_Month_Equal_0) {
    // Arrange
    double oklad = 10000;
    double admin_hours = 8 * 20;
    double overtime_hours = 0;
    char *month = const_cast<char*>("May");
    double wages = 0;
    Wages ivan(oklad, admin_hours, overtime_hours, month);

    // Act & assert
    EXPECT_TRUE(ivan.calculationFullWages() == wages);
}
