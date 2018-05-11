// Copyright 2018 Vyunov Roman

#include "../modules/DebtServiceCosts/include/DebtService.h"

DebtService::DebtService(float loan_amount, float loan_term, float loan_rate, DebtServiceType dt) {
    if (loan_amount < 0) {
        throw "Incorrect amount";
    } else {
        loan_amount_ = loan_amount;
        loan_balance_ = loan_amount_;
    }

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

    service_type_ = dt;
}

DebtService::DebtService(const DebtService &ds) {
    loan_amount_ = ds.loan_amount_;
    loan_balance_ = ds.loan_balance_;
    loan_rate_ = ds.loan_rate_;
    loan_term_ = ds.loan_term_;
    service_type_ = ds.service_type_;
}
DebtService& DebtService::operator= (const DebtService& dt){
    loan_amount_ = dt.loan_amount_;
    loan_balance_ = dt.loan_balance_;
    loan_rate_ = dt.loan_rate_;
    loan_term_ = dt.loan_term_;
    service_type_ = dt.service_type_;

    return *this;
}
