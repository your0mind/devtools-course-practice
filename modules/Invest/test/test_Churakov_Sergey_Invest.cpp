// Copyright 2018 Churakov Sergey

#include <gtest/gtest.h>

#include "include/Invest.h"

TEST(Churakov_Sergey_Investition, can_create_empty_investition) {
    ASSERT_NO_THROW(Investition inv);
}

TEST(Churakov_Sergey_Investition, can_create_investition ) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;

    ASSERT_NO_THROW(Investition inv(years, arr1, arr2, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_investition_with_negative_year ) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = -2;
    rate = 20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;

    ASSERT_ANY_THROW(Investition inv(years, arr1, arr2, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_investition_with_negative_rate) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = -20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;

    ASSERT_ANY_THROW(Investition inv(years, arr1, arr2, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_investition_with_huge_rate) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 201;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;

    ASSERT_ANY_THROW(Investition inv(years, arr1, arr2, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_investition_with_negative_income) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 20;
    arr1[0] = arr1[1] = -10;
    arr2[0] = arr2[1] = 10;

    ASSERT_ANY_THROW(Investition inv(years, arr1, arr2, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_investition_with_negative_expenses) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = -10;

    ASSERT_ANY_THROW(Investition inv(years, arr1, arr2, rate));
}

TEST(Churakov_Sergey_Investition, can_get_year_count) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_EQ(inv.GetYearCount(), 2);
}

TEST(Churakov_Sergey_Investition, can_get_rate) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_EQ(inv.GetRate(), 20);
}

TEST(Churakov_Sergey_Investition, can_get_incomes) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_EQ(*(inv.GetIncomes())+0, 10);
}

TEST(Churakov_Sergey_Investition, can_get_expenses) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_EQ(*(inv.GetExpenses()) + 0, 10);
}

TEST(Churakov_Sergey_Investition, can_get_income_of_year) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_EQ(inv.GetIncomeOfYear(0), 10);
}

TEST(Churakov_Sergey_Investition, can_get_expense_of_year) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_EQ(inv.GetExpenseOfYear(0), 10);
}

TEST(Churakov_Sergey_Investition, cant_get_income_of_unexisting_year) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;
    Investition inv(years, arr1, arr2, rate);

    ASSERT_ANY_THROW(inv.GetIncomeOfYear(10));
}

TEST(Churakov_Sergey_Investition, cant_get_expense_of_unexisting_year) {
    money* arr1 = new money[2];
    money* arr2 = new money[2];
    int years;
    double rate;

    years = 2;
    rate = 20;
    arr1[0] = arr1[1] = 10;
    arr2[0] = arr2[1] = 10;
    Investition inv(years, arr1, arr2, rate);

    ASSERT_ANY_THROW(inv.GetExpenseOfYear(10));
}

TEST(Churakov_Sergey_Investition, can_set_rate) {
    double rate;
    Investition inv;

    rate = 20;
    inv.SetRate(rate);

    EXPECT_EQ(inv.GetRate(), rate);
}

TEST(Churakov_Sergey_Investition, can_set_year_count) {
    int years;
    Investition inv;

    years = 3;
    inv.SetYearCount(years);

    EXPECT_EQ(inv.GetYearCount(), years);
}

TEST(Churakov_Sergey_Investition, can_set_incomes) {
    money* arr = new money[2];
    Investition inv;

    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        arr[i] = i;
    inv.SetIncomes(arr);

    EXPECT_TRUE(inv.GetIncomeOfYear(0) == 0 && inv.GetIncomeOfYear(1) == 1);
}

TEST(Churakov_Sergey_Investition, can_set_expenses) {
    money* arr = new money[2];
    Investition inv;

    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        arr[i] = i;
    inv.SetExpenses(arr);

    EXPECT_TRUE(inv.GetExpenseOfYear(0) == 0 && inv.GetExpenseOfYear(1) == 1);
}

TEST(Churakov_Sergey_Investition, cant_set_invalid_rate) {
    double rate;
    Investition inv;

    rate = -20;

    ASSERT_ANY_THROW(inv.SetRate(rate));
}

TEST(Churakov_Sergey_Investition, cant_set_invalid_year_count) {
    int years;
    Investition inv;

    years = -3;

    ASSERT_ANY_THROW(inv.SetYearCount(years));
}

TEST(Churakov_Sergey_Investition, cant_set_negative_incomes) {
    money* arr = new money[2];
    Investition inv;

    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        arr[i] = -i;

    ASSERT_ANY_THROW(inv.SetIncomes(arr));
}

TEST(Churakov_Sergey_Investition, DISABLED_cant_set_incomes_with_small_size_of_array) {
    money* arr = new money[1];
    Investition inv;

    inv.SetYearCount(2);
    arr[0] = 1;

    ASSERT_ANY_THROW(inv.SetIncomes(arr));
}

TEST(Churakov_Sergey_Investition, cant_set_negative_expenses) {
    money* arr = new money[2];
    Investition inv;

    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        arr[i] = -i;

    ASSERT_ANY_THROW(inv.SetExpenses(arr));
}

TEST(Churakov_Sergey_Investition, DISABLED_cant_set_expenses_with_small_size_of_array) {
    money* arr = new money[1];
    Investition inv;

    inv.SetYearCount(2);
    arr[0] = 1;

    ASSERT_ANY_THROW(inv.SetExpenses(arr));
}

TEST(Churakov_Sergey_Investition, can_find_NPV) {
    money* arr1 = new money[5];
    money* arr2 = new money[5];
    int years;
    double rate;

    years = 5;
    rate = 8;
    arr2[0] = 2000;
    arr1[0] = arr2[1] = arr2[2] = arr2[3] = arr2[4] = 0;
    arr1[1] = 1000;
    arr1[2] = arr1[3] = 800;
    arr1[4] = 600;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_TRUE(inv.FindNPV() > 687 && inv.FindNPV() < 688);
}

TEST(Churakov_Sergey_Investition, can_find_NPV_for_rate) {
    money* arr1 = new money[5];
    money* arr2 = new money[5];
    int years;
    double rate;

    years = 5;
    rate = 8;
    arr2[0] = 2000;
    arr1[0] = arr2[1] = arr2[2] = arr2[3] = arr2[4] = 0;
    arr1[1] = 1000;
    arr1[2] = arr1[3] = 800;
    arr1[4] = 600;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_EQ(inv.FindNPV(), inv.FindNPV(8));
}

TEST(Churakov_Sergey_Investition, can_find_recoupment_time) {
    money* arr1 = new money[5];
    money* arr2 = new money[5];
    int years;
    double rate;

    years = 5;
    rate = 8;
    arr2[0] = 2000;
    arr1[0] = arr2[1] = arr2[2] = arr2[3] = arr2[4] = 0;
    arr1[1] = 1000;
    arr1[2] = arr1[3] = 800;
    arr1[4] = 600;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_EQ(inv.FindRecoupmentTime(), 3);
}

TEST(Churakov_Sergey_Investition, cant_find_recoupment_time_when_no_answer) {
    money* arr1 = new money[5];
    money* arr2 = new money[5];
    int years;
    double rate;

    years = 5;
    rate = 88;
    arr2[0] = 2000;
    arr1[0] = arr2[1] = arr2[2] = arr2[3] = arr2[4] = 0;
    arr1[1] = 1000;
    arr1[2] = arr1[3] = 800;
    arr1[4] = 600;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_EQ(inv.FindRecoupmentTime(), -1);
}

TEST(Churakov_Sergey_Investition, can_find_IRR) {
    money* arr1 = new money[5];
    money* arr2 = new money[5];
    int years;
    double rate;

    years = 5;
    rate = 8;
    arr2[0] = 2000;
    arr1[0] = arr2[1] = arr2[2] = arr2[3] = arr2[4] = 0;
    arr1[1] = 1000;
    arr1[2] = arr1[3] = 800;
    arr1[4] = 600;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_TRUE(inv.FindIRR() > 24 && inv.FindIRR() < 24.2);
}

TEST(Churakov_Sergey_Investition, cant_find_IRR_when_it_is_infinite) {
    money* arr1 = new money[5];
    money* arr2 = new money[5];
    int years;
    double rate;

    years = 5;
    rate = 8;
    arr2[0] = 0;
    arr1[0] = arr2[1] = arr2[2] = arr2[3] = arr2[4] = 0;
    arr1[1] = 1000;
    arr1[2] = arr1[3] = 800;
    arr1[4] = 600;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_EQ(inv.FindIRR(), -2);
}

TEST(Churakov_Sergey_Investition, cant_find_IRR_when_there_is_no_recoupment) {
    money* arr1 = new money[5];
    money* arr2 = new money[5];
    int years;
    double rate;

    years = 5;
    rate = 8;
    arr2[0] = 2000;
    arr1[0] = arr2[1] = arr2[2] = arr2[3] = arr2[4] = 0;
    arr1[1] = 100;
    arr1[2] = arr1[3] = 80;
    arr1[4] = 60;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_EQ(inv.FindIRR(), -1);
}

TEST(Churakov_Sergey_Investition, can_find_PBIndex) {
    money* arr1 = new money[5];
    money* arr2 = new money[5];
    int years;
    double rate;

    years = 5;
    rate = 8;
    arr2[0] = 2000;
    arr1[0] = arr2[1] = arr2[2] = arr2[3] = arr2[4] = 0;
    arr1[1] = 1000;
    arr1[2] = arr1[3] = 800;
    arr1[4] = 600;
    Investition inv(years, arr1, arr2, rate);

    EXPECT_TRUE(inv.FindPBIndex()> 0.46 && inv.FindPBIndex() <0.47);
}

TEST(Churakov_Sergey_Investition, cant_fint_PBIndex_with_multiple_expenses) {
    money* arr1 = new money[5];
    money* arr2 = new money[5];
    int years;
    double rate;

    years = 5;
    rate = 8;
    arr2[0] = 2000;
    arr1[0] = arr2[1] = arr2[2] = arr2[3] = 0;
    arr2[4] = 10;
    arr1[1] = 1000;
    arr1[2] = arr1[3] = 800;
    arr1[4] = 600;
    Investition inv(years, arr1, arr2, rate);

    ASSERT_ANY_THROW(inv.FindPBIndex());
}


