// Copyright 2018 Vyunov Roman

#include "../modules/DebtServiceCosts/include/DebtService.h"

DebtService::DebtService(int loan_amount, int loan_term, int loan_rate) {
    if (loan_amount < 0)
        throw "Incorrect amount";
    else
        loan_amount_ = loan_amount;

    if (loan_term < 1) {
        throw "Incorrect term";
    } else {
        loan_term_ = loan_term;
    }

    if (loan_rate < 0) {
        throw "Incorrect rate";
    } else {
        loan_rate_ = loan_rate;
    }
}
