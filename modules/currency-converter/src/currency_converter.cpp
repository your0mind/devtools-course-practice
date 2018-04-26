// Copyright 2018 Grishin Anton

#include "include/currency_converter.h"

CurrencyConverter::CurrencyConverter() : usd_price(60), eur_price(75) {}

CurrencyConverter::CurrencyConverter(const double usd, const double eur)
                      : usd_price(usd), eur_price(eur) {}

CurrencyConverter::CurrencyConverter(const CurrencyConverter& z)
                             : usd_price(z.getUsdPrice()), eur_price(z.getEurPrice()) {}

CurrencyConverter& CurrencyConverter::operator=(const CurrencyConverter& z) {
    usd_price = z.getUsdPrice();
    eur_price = z.getEurPrice();

    return *this;
}

double CurrencyConverter::getUsdPrice() const {
    return usd_price;
}

double CurrencyConverter::getEurPrice() const {
    return eur_price;
}


void CurrencyConverter::setUsdPrice(const double usd) {
    usd_price = usd;
}

void CurrencyConverter::setEurPrice(const double eur) {
    eur_price = eur;
}

double CurrencyConverter::roubleToDollar(double rub) {
    return rub / getUsdPrice();
}

double CurrencyConverter::dollarToRouble(double usd) {
    return usd * getUsdPrice();
}

double CurrencyConverter::roubleToEuro(double rub) {
    return rub / getEurPrice();
}

double CurrencyConverter::euroToRouble(double eur) {
    return eur * getEurPrice();
}

double CurrencyConverter::dollarToEuro(double usd) {
    return usd * getUsdPrice() / getEurPrice();
}

double CurrencyConverter::euroToDollar(double eur) {
    return eur * getEurPrice() / getUsdPrice();
}

bool CurrencyConverter::operator == (const CurrencyConverter& z) const {
    if(((this->getUsdPrice() - z.getUsdPrice()) == 0) &&
      ((this->getEurPrice() - z.getEurPrice()) == 0)) return true;
    return false;
}

bool CurrencyConverter::operator != (const CurrencyConverter& z) const {
    return !(*this == z);
}
