// Copyright 2018 Grishin Anton

#ifndef MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_
#define MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_


class CurrencyConverter {
 public:
    CurrencyConverter();
    CurrencyConverter(const double usd, const double eur, const double azn, const double gbp);
    CurrencyConverter(const CurrencyConverter& z);

    CurrencyConverter& operator=(const CurrencyConverter& z);

    double getUsdPrice() const;
    double getEurPrice() const;

    void setUsdPrice(const double usd);
    void setEurPrice(const double eur);

    double roubleToDollar(double rouble);
    double dollarToRouble(double dollar);

    double roubleToEuro(double rouble);
    double euroToRouble(double euro);

    double dollarToEuro(double dollar);
    double euroToDollar(double euro);

 private:
    double usd_price;
    double eur_price;

};

#endif  // MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_
