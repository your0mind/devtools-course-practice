// Copyright 2018 Vyunov Roman

#ifndef MODULES_DEBTSERVICECOSTS_INCLUDE_DEBTSERVICE_H_
#define MODULES_DEBTSERVICECOSTS_INCLUDE_DEBTSERVICE_H_

class DebtService {
 private:
    int loan_amount_;
    int loan_term_;
    int loan_rate_;

 public:
    // DebtService ():loan_amount_(0), loan_term_(0), loan_rate_(0) {}
    // DebtService& operator= (const DebtService& ds);
    // DebtService& operator= (const DebtService&& ds);
    DebtService(int loan_amount, int loan_term, int loan_rate);

    // virtual ~DebtService ();
};

#endif // MODULES_DEBTSERVICECOSTS_INCLUDE_DEBTSERVICE_H_
