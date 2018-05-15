// Copyright 2018 Vyunov Roman

#ifndef MODULES_DEBTSERVICECOSTS_INCLUDE_DEBTSERVICE_H_
#define MODULES_DEBTSERVICECOSTS_INCLUDE_DEBTSERVICE_H_

#include <math.h>

enum DebtServiceType {ONE_PAYMENT_AT_THE_END,
                      PRINCIPAL_DEBT_ONE_PAYMENT_AT_THE_END,
                      EQUAL_ANNUAL_PAYMENTS};

class DebtService {
 private:
    float loan_amount_;  // Сумма займа
    int loan_term_;  // Срок займа в единицах времени
    int curr_term_;  // Сколько времени прошло от начала займа
    float loan_rate_;  // Процент займа за единицу времени
    float loan_balance_;  // Остаток по займу
    DebtServiceType service_type_;  //тип обслуживания займа

 public:
    DebtService():loan_amount_(0), loan_term_(0), curr_term_(0), loan_rate_(0),
        loan_balance_(0), service_type_(ONE_PAYMENT_AT_THE_END) {}
    DebtService(float loan_amount, int loan_term, float loan_rate, DebtServiceType dt);
    DebtService(const DebtService& ds);
    DebtService& operator= (const DebtService& ds);

    float GetTotalPayout();
    void MakingPayment(float pay_amnt);
    void SetNextTime();
    float GetBalance();
    ~DebtService() {}
};

#endif  // MODULES_DEBTSERVICECOSTS_INCLUDE_DEBTSERVICE_H_
