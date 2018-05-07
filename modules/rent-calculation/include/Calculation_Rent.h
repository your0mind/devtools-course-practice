// Copyright 2018 Boris Ermachenko

#ifndef MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_H_
#define MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_H_

class Calculation_Rent{
    public:
        Calculation_Rent() {}
        ~Calculation_Rent() {}
        double Rent_Accumulated_Yearly_postnumerando_with_hard_rate(double amount_of_payment, double rent_term, double interest_rate);
        double Rent_Accumulated_Yearly_postnumerando_with_easy_rate(double amount_of_payment, double rent_term, double interest_rate);
        double Rent_Accumulated_Yearly_prenumerando_with_hard_rate(double amount_of_payment, double rent_term, double interest_rate);
        double Rent_Accumulated_Yearly_pretnumerando_with_easy_rate(double amount_of_payment, double rent_term, double interest_rate);
        double Rent_Accumulated_P_Period_postnumerando(double amount_of_payment, double rent_term, double nominal_rate, int number_of_compounding_per_year, int number_of_payments_per_year);
        double Rent_Accumulated_P_Period_prenumerando(double amount_of_payment, double rent_term, double nominal_rate, int number_of_compounding_per_year, int number_of_payments_per_year);
        double Rent_Modern_Yearly_postnumerando_with_hard_rate(double amount_of_payment, double rent_term, double interest_rate);
        double Rent_Modern_Yearly_postnumerando_with_easy_rate(double amount_of_payment, double rent_term, double interest_rate);
        double Rent_Modern_Yearly_prenumerando_with_hard_rate(double amount_of_payment, double rent_term, double interest_rate);
        double Rent_Modern_Yearly_pretnumerando_with_easy_rate(double amount_of_payment, double rent_term, double interest_rate);
        double Rent_Modern_P_Period_postnumerando(double amount_of_payment, double rent_term, double nominal_rate, int number_of_compounding_per_year, int number_of_payments_per_year);
        double Rent_Modern_P_Period_prenumerando(double amount_of_payment, double rent_term, double nominal_rate, int number_of_compounding_per_year, int number_of_payments_per_year);
};

#endif  MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_H_

