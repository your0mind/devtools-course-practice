// Copyright 2018 Grishin Anton

#ifndef MODULES_CURRENCY_CONVERTER_INCLUDE_COMPLEX_NUMBER_H_
#define MODULES_CURRENCY_CONVERTER_INCLUDE_COMPLEX_NUMBER_H_


class ComplexNumber;

class CurrencyConverter {
 public:
    CurrencyConverter();
    CurrencyConverter(const double usd, const double eur, const double azn, const double gbp);
    CurrencyConverter(const CurrencyConverter& z);

    CurrencyConverter& operator=(const CurrencyConverter& z);

    double getUsdPrice() const;
    double getEurPrice() const;
    double getAznPrice() const;
    double getGbpPrice() const;
    void setUsdPrice(const double usd);
    void setEurPrice(const double eur);
    void setAznPrice(const double azn);
    void setGbpPrice(const double gbp);


 private:
    double usd_price;
    double eur_price;
    double azn_price;
    double gbp_price;
};

#endif  // MODULES_CURRENCY_CONVERTER_INCLUDE_COMPLEX_NUMBER_H_
