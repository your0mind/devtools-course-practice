// Copyright 2018 Boris Ermachenko

#ifndef MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_H_
#define MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_H_

class Calculation_Rent{
    public:
        Calculation_Rent() {}
        ~Calculation_Rent() {}
        double Rent_Accum_Yearly_postnumerando_hard_rate(double amount_payment,
                                double rent_term, double interest_rate);
        double Rent_Accum_Yearly_postnumerando_easy_rate(double amount_payment,
                                double rent_term, double interest_rate);
        double Rent_Accum_Yearly_prenumerando_hard_rate(double amount_payment,
                                double rent_term, double interest_rate);
        double Rent_Accum_Yearly_pretnumerando_easy_rate(double amount_payment,
                                double rent_term, double interest_rate);
        double Rent_Accum_P_Period_postnumerando(double amount_payment,
                                    double rent_term, double nominal_rate,
                int number_compounding_per_year, int number_payments_per_year);
        double Rent_Accum_P_Period_prenumerando(double amount_payment,
                                                        double rent_term,
                double nominal_rate, int number_compounding_per_year, 
                int number_payments_per_year);
        double Rent_Modern_Yearly_postnumerando_hard_rate(double amount_payment, 
                double rent_term, double interest_rate);
        double Rent_Modern_Yearly_postnumerando_easy_rate(double amount_payment, 
                double rent_term, double interest_rate);
        double Rent_Modern_Yearly_prenumerando_hard_rate(double amount_payment, 
                double rent_term, double interest_rate);
        double Rent_Modern_Yearly_pretnumerando_easy_rate(double amount_payment, 
                double rent_term, double interest_rate);
        double Rent_Modern_P_Period_postnumerando(double amount_payment,
                double rent_term, double nominal_rate, 
                int number_compounding_per_year,
                int number_payments_per_year);
        double Rent_Modern_P_Period_prenumerando(double amount_payment, 
                    double rent_term, double nominal_rate, 
                    int number_compounding_per_year,
                    int number_payments_per_year);
};

#endif // MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_H_

