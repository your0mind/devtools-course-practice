// Copyright 2018 Churakov Sergey

#include "include/Invest.h"
#include <iostream>
#include <cmath>

Investition::Investition() {
    YearCount = 0;
    RatePercent = 0;
    Incomes = new money[1];
    Incomes[0] = 0;
    Expenses = new money[1];
    Expenses[0] = 0;
}

Investition::Investition(const int& years, money* Income_arr,
                        money* Expenses_arr, const double& rate) {
    if (years < 0 || rate < 0|| rate>199)
        throw WRONG_VALUE;
    YearCount = years;
    RatePercent = rate;
    Incomes = new money[years];
    Expenses = new money[years];
    for (int i = 0; i < YearCount; i++) {
        if (Income_arr[i] < 0 || Expenses_arr[i] < 0)
            throw WRONG_VALUE;
        Incomes[i] = Income_arr[i];
        Expenses[i] = Expenses_arr[i];
    }
}

Investition::~Investition() {
    if (Incomes != NULL)
        delete[] Incomes;
    if (Expenses != NULL)
        delete[] Expenses;
}

void Investition::SetRate(const double& rate) {
    if (rate < 0)
        throw WRONG_VALUE;
    RatePercent = rate;
}

void Investition:: SetYearCount(const int& years) {
    if (years < 0)
        throw WRONG_VALUE;
    if (years != YearCount) {
        money* buf1 = new money[YearCount];
        money* buf2 = new money[YearCount];
        for (int i = 0; i < YearCount; i++) {
            buf1[i] = Incomes[i];
            buf2[i] = Expenses[i];
        }
        delete[] Incomes;
        delete[] Expenses;
        Incomes = new money[years];
        Expenses = new money[years];
        for (int i = 0; i < years; i++) {
            if (i < YearCount) {
                Incomes[i] = buf1[i];
                Expenses[i] = buf2[i];
            } else {
                Expenses[i] = Incomes[i] = 0;
            }
        }
        delete [] buf1;
        delete [] buf2;
    }
    YearCount = years;
}

void Investition::SetIncomes(money* Income_arr) {
    for (int i = 0; i < YearCount; i++) {
        if (Income_arr[i] < 0)
            throw WRONG_VALUE;
        Incomes[i] = Income_arr[i];
    }
}

void Investition::SetExpenses(money* Expenses_arr) {
    for (int i = 0; i < YearCount; i++) {
        if (Expenses_arr[i] < 0)
            throw WRONG_VALUE;
        Expenses[i] = Expenses_arr[i];
    }
}

int Investition::GetYearCount() const {
    return YearCount;
}

double Investition::GetRate() const {
    return RatePercent;
}

money Investition::GetIncomeOfYear(const int& year) const {
    if (year > YearCount || year < 0)
        throw WRONG_VALUE;
    return Incomes[year];
}

money Investition::GetExpenseOfYear(const int& year) const {
    if (year > YearCount || year < 0)
        throw WRONG_VALUE;
    return Expenses[year];
}

money* Investition::GetIncomes() const {
    money* tmp = new money[YearCount];
    for (int i = 0; i < YearCount; i++)
        tmp[i] = Incomes[i];
    return tmp;
}

money* Investition::GetExpenses() const {
    money* tmp = new money[YearCount];
    for (int i = 0; i < YearCount; i++)
        tmp[i] = Expenses[i];
    return tmp;
}

double Investition::FindNPV() const {
    double NPV = 0;
    for (int i = 0; i < YearCount; i++) {
        NPV *= 1 + RatePercent / 100;
        NPV += Incomes[i] - Expenses[i];
    }
    return NPV/pow(1 + RatePercent / 100, YearCount - 1);
}

double Investition::FindNPV(const double& rate) const {
    double NPV = 0;
    for (int i = 0; i < YearCount; i++) {
        NPV *= 1 + rate / 100;
        NPV += Incomes[i] - Expenses[i];
    }
    return NPV/pow(1 + rate / 100, YearCount - 1);
}

int Investition::FindRecoupmentTime() const {
    double NPV = 0;
    for (int i = 0; i < YearCount; i++) {
        NPV *= 1 + RatePercent / 100;
        NPV += Incomes[i] - Expenses[i];
        if (NPV > 0)
            return i;
    }
    return -1;
}

double Investition::FindPBIndex() const {
    for (int i = 1; i < YearCount; i++)
        if (Expenses[i] != 0)
            throw WRONG_VALUE;
    double NPV = Incomes[0]-Expenses[0];
    for (int i = 1; i < YearCount; i++) {
        NPV *= 1 + RatePercent / 100;
        NPV += Incomes[i];
    }
    return NPV/Expenses[0];
}

double Investition::FindIRR() const {
    if (this->FindNPV(0.0) < 0)
        return -1;
    if (this->FindNPV(199.0) > 0)
        return -2;
    for (double i = 0; i < 200; i+=0.1)
        if (this->FindNPV(i) <= 0)
            return i-0.1;
    return -3;
}

// void Investition::Print() const {
//     cout<<"Number of years is "<<YearCount<<endl;
//     cout<<"Rate is "<<(1+RatePercent/100)<<endl;
//     cout<<"Expenses        Incomes" << endl;
//     cout<<"______________________________________"<<endl;
//     for (int i = 0; i < YearCount; i++)
//         cout<<Expenses[i]<<"        "<<Incomes[i]<<endl;
//     cout<<"______________________________________"<<endl;
//     cout<<"NPV is "<<this->FindNPV()<<endl;
//     if (this->FindRecoupmentTime() > 0)
//         cout<<"Recoupment time is " << this->FindRecoupmentTime()<<endl;
//     else {
//         if (this->FindRecoupmentTime() == 0)
//             cout<<"Investition recoups right away"<<endl;
//         else
//             cout<<"Investition doesnt recoup"<<endl;
//     }
//     if (this->FindIRR() >= 0)
//         cout<<"IRR is " << this->FindIRR()<<endl;
//     bool flag = true;
//     for (int i = 1; i < YearCount; i++)
//         if (Expenses[i] != 0)
//             flag = false;
//     if (flag)
//     cout<<"PBIndex is " <<this->FindPBIndex();
// }
