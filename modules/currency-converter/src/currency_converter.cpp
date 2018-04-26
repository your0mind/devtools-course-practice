// Copyright 2018 Grishin Anton

#include "include/currency_converter.h"

CurrencyConverter::CurrencyConverter() : usd_price(60), eur_price(75) {}

CurrencyConverter::CurrencyConverter(const double usd, const double eur, const double azn, const double gbp)
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

double CurrencyConverter::roubleToDollar(double rouble) {
    return rouble / getUsdPrice();
}

double CurrencyConverter::dollarToRouble(double dollar) {
    return dollar * getUsdPrice();
}

double CurrencyConverter::roubleToEuro(double rouble) {
    return rouble / getEurPrice();
}

double CurrencyConverter::euroToRouble(double euro) {
    return euro * getEurPrice();
}

double CurrencyConverter::dollarToEuro(double dollar) {
    return dollar * getUsdPrice() / getEurPrice();
}

double CurrencyConverter::euroToDollar(double euro) {
    return euro * getEurPrice() / getUsdPrice();
}
