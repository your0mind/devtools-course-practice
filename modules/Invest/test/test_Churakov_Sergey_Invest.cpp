// Copyright 2018 Churakov Sergey

#include <gtest/gtest.h>

#include "include/Invest.h"
#include <vector>

TEST(Churakov_Sergey_Investition, can_create_empty_investition) {
    ASSERT_NO_THROW(Investition inv);
}

TEST(Churakov_Sergey_Investition, can_create_investition ) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;

    ASSERT_NO_THROW(Investition inv(years, a1, a2, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_investition_with_negative_year ) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = -2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;

    ASSERT_ANY_THROW(Investition inv(years, a1, a2, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_investition_with_negative_rate) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = -20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;

    ASSERT_ANY_THROW(Investition inv(years, a1, a2, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_investition_with_huge_rate) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 201;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;

    ASSERT_ANY_THROW(Investition inv(years, a1, a2, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_invest_with_neg_income) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = -10;
    a2[0] = a2[1] = 10;

    ASSERT_ANY_THROW(Investition inv(years, a1, a2, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_invest_with_neg_expenses) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = -10;

    ASSERT_ANY_THROW(Investition inv(years, a1, a2, rate));
}

TEST(Churakov_Sergey_Investition, can_get_year_count) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;
    Investition inv(years, a1, a2, rate);

    EXPECT_EQ(inv.GetYearCount(), 2);
}

TEST(Churakov_Sergey_Investition, can_get_rate) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;
    Investition inv(years, a1, a2, rate);

    EXPECT_EQ(inv.GetRate(), 20);
}

TEST(Churakov_Sergey_Investition, can_get_incomes) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;
    Investition inv(years, a1, a2, rate);

    EXPECT_EQ(*(inv.GetIncomes())+0, 10);
}

TEST(Churakov_Sergey_Investition, can_get_expenses) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;
    Investition inv(years, a1, a2, rate);

    EXPECT_EQ(*(inv.GetExpenses()) + 0, 10);
}

TEST(Churakov_Sergey_Investition, can_get_income_of_year) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;
    Investition inv(years, a1, a2, rate);

    EXPECT_EQ(inv.GetIncomeOfYear(0), 10);
}

TEST(Churakov_Sergey_Investition, can_get_expense_of_year) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;
    Investition inv(years, a1, a2, rate);

    EXPECT_EQ(inv.GetExpenseOfYear(0), 10);
}

TEST(Churakov_Sergey_Investition, cant_get_income_of_unexisting_year) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;
    Investition inv(years, a1, a2, rate);

    ASSERT_ANY_THROW(inv.GetIncomeOfYear(10));
}

TEST(Churakov_Sergey_Investition, cant_get_expense_of_unexisting_year) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;
    Investition inv(years, a1, a2, rate);

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

TEST(Churakov_Sergey_Investition, can_set_lesser_year_count) {
    std::vector<money> a1(2);
    std::vector<money> a2(2);
    int years;
    double rate;

    years = 2;
    rate = 20;
    a1[0] = a1[1] = 10;
    a2[0] = a2[1] = 10;
    Investition inv(years, a1, a2, rate);
    years = 1;
    inv.SetYearCount(years);

    EXPECT_EQ(inv.GetYearCount(), years);
}

TEST(Churakov_Sergey_Investition, can_set_incomes) {
    std::vector<money> a(2);
    Investition inv;

    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        a[i] = i;
    inv.SetIncomes(a);

    EXPECT_TRUE(inv.GetIncomeOfYear(0) == 0 && inv.GetIncomeOfYear(1) == 1);
}

TEST(Churakov_Sergey_Investition, can_set_expenses) {
    std::vector<money> a(2);
    Investition inv;

    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        a[i] = i;
    inv.SetExpenses(a);

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
    std::vector<money> a(2);
    Investition inv;

    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        a[i] = -i;

    ASSERT_ANY_THROW(inv.SetIncomes(a));
}

TEST(Churakov_Sergey_Investition, cant_set_incomes_with_small_a) {
    std::vector<money> a(1);
    Investition inv;

    inv.SetYearCount(2);
    a[0] = 1;

    ASSERT_ANY_THROW(inv.SetIncomes(a));
}

TEST(Churakov_Sergey_Investition, cant_set_negative_expenses) {
    std::vector<money> a(2);
    Investition inv;

    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        a[i] = -i;

    ASSERT_ANY_THROW(inv.SetExpenses(a));
}

TEST(Churakov_Sergey_Investition, cant_set_expenses_with_small_a) {
    std::vector<money> a(1);
    Investition inv;

    inv.SetYearCount(2);
    a[0] = 1;

    ASSERT_ANY_THROW(inv.SetExpenses(a));
}

TEST(Churakov_Sergey_Investition, can_find_NPV) {
    std::vector<money> a1(5);
    std::vector<money> a2(5);
    int years;
    double rate;

    years = 5;
    rate = 8;
    a2[0] = 2000;
    a1[0] = a2[1] = a2[2] = a2[3] = a2[4] = 0;
    a1[1] = 1000;
    a1[2] = a1[3] = 800;
    a1[4] = 600;
    Investition inv(years, a1, a2, rate);

    EXPECT_TRUE(inv.FindNPV() > 687 && inv.FindNPV() < 688);
}

TEST(Churakov_Sergey_Investition, can_find_NPV_for_rate) {
    std::vector<money> a1(5);
    std::vector<money> a2(5);
    int years;
    double rate;

    years = 5;
    rate = 8;
    a2[0] = 2000;
    a1[0] = a2[1] = a2[2] = a2[3] = a2[4] = 0;
    a1[1] = 1000;
    a1[2] = a1[3] = 800;
    a1[4] = 600;
    Investition inv(years, a1, a2, rate);

    EXPECT_EQ(inv.FindNPV(), inv.FindNPV(8));
}

TEST(Churakov_Sergey_Investition, can_find_recoupment_time) {
    std::vector<money> a1(5);
    std::vector<money> a2(5);
    int years;
    double rate;

    years = 5;
    rate = 8;
    a2[0] = 2000;
    a1[0] = a2[1] = a2[2] = a2[3] = a2[4] = 0;
    a1[1] = 1000;
    a1[2] = a1[3] = 800;
    a1[4] = 600;
    Investition inv(years, a1, a2, rate);

    EXPECT_EQ(inv.FindRecoupmentTime(), 3);
}

TEST(Churakov_Sergey_Investition, cant_find_recoupment_time_when_no_answer) {
    std::vector<money> a1(5);
    std::vector<money> a2(5);
    int years;
    double rate;

    years = 5;
    rate = 88;
    a2[0] = 2000;
    a1[0] = a2[1] = a2[2] = a2[3] = a2[4] = 0;
    a1[1] = 1000;
    a1[2] = a1[3] = 800;
    a1[4] = 600;
    Investition inv(years, a1, a2, rate);

    EXPECT_EQ(inv.FindRecoupmentTime(), -1);
}

TEST(Churakov_Sergey_Investition, can_find_IRR) {
    std::vector<money> a1(5);
    std::vector<money> a2(5);
    int years;
    double rate;

    years = 5;
    rate = 8;
    a2[0] = 2000;
    a1[0] = a2[1] = a2[2] = a2[3] = a2[4] = 0;
    a1[1] = 1000;
    a1[2] = a1[3] = 800;
    a1[4] = 600;
    Investition inv(years, a1, a2, rate);

    EXPECT_TRUE(inv.FindIRR() > 24 && inv.FindIRR() < 24.2);
}

TEST(Churakov_Sergey_Investition, cant_find_IRR_when_it_is_infinite) {
    std::vector<money> a1(5);
    std::vector<money> a2(5);
    int years;
    double rate;

    years = 5;
    rate = 8;
    a2[0] = 0;
    a1[0] = a2[1] = a2[2] = a2[3] = a2[4] = 0;
    a1[1] = 1000;
    a1[2] = a1[3] = 800;
    a1[4] = 600;
    Investition inv(years, a1, a2, rate);

    EXPECT_EQ(inv.FindIRR(), -2);
}

TEST(Churakov_Sergey_Investition, cant_find_IRR_when_there_is_no_recoupment) {
    std::vector<money> a1(5);
    std::vector<money> a2(5);
    int years;
    double rate;

    years = 5;
    rate = 8;
    a2[0] = 2000;
    a1[0] = a2[1] = a2[2] = a2[3] = a2[4] = 0;
    a1[1] = 100;
    a1[2] = a1[3] = 80;
    a1[4] = 60;
    Investition inv(years, a1, a2, rate);

    EXPECT_EQ(inv.FindIRR(), -1);
}

TEST(Churakov_Sergey_Investition, can_find_PBIndex) {
    std::vector<money> a1(5);
    std::vector<money> a2(5);
    int years;
    double rate;

    years = 5;
    rate = 8;
    a2[0] = 2000;
    a1[0] = a2[1] = a2[2] = a2[3] = a2[4] = 0;
    a1[1] = 1000;
    a1[2] = a1[3] = 800;
    a1[4] = 600;
    Investition inv(years, a1, a2, rate);

    EXPECT_TRUE(inv.FindPBIndex()> 0.46 && inv.FindPBIndex() <0.47);
}

TEST(Churakov_Sergey_Investition, cant_fint_PBIndex_with_multiple_expenses) {
    std::vector<money> a1(5);
    std::vector<money> a2(5);
    int years;
    double rate;

    years = 5;
    rate = 8;
    a2[0] = 2000;
    a1[0] = a2[1] = a2[2] = a2[3] = 0;
    a2[4] = 10;
    a1[1] = 1000;
    a1[2] = a1[3] = 800;
    a1[4] = 600;
    Investition inv(years, a1, a2, rate);

    ASSERT_ANY_THROW(inv.FindPBIndex());
}


