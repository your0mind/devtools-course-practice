// Copyright 2018 Grishin Anton

#include "include/currency_converter.h"

#include <stdbool.h>
#include <string>
#include <limits>

const double eps = std::numeric_limits<double>::epsilon();

CurrencyConverter::CurrencyConverter() : usd_price(60), eur_price(75), azn_price(35), gbp_price(86) {}

CurrencyConverter::CurrencyConverter(const double usd, const double eur, const double azn, const double gbp)
                      : usd_price(usd), eur_price(eur), azn_price(azn), gbp_price(gbp) {}

CurrencyConverter::CurrencyConverter(const CurrencyConverter& z)
                             : usd_price(z.getUsdPrice()), eur_price(z.getEurPrice()),
                               azn_price(z.getAznPrice()), gbp_price(z.getGbpPrice()) {}

CurrencyConverter& CurrencyConverter::operator=(const CurrencyConverter& z) {
    usd_price = z.getUsdPrice();
    eur_price = z.getEurPrice();
    azn_price = z.getAznPrice();
    gbp_price = z.getGbpPrice();

    return *this;
}

double CurrencyConverter::getUsdPrice() const {
    return usd_price;
}

double CurrencyConverter::getEurPrice() const {
    return eur_price;
}

double CurrencyConverter::getAznPrice() const {
    return azn_price;
}

double CurrencyConverter::getGbpPrice() const {
    return gbp_price;
}

void CurrencyConverter::setUsdPrice(const double usd) {
    usd_price = usd;
}

void CurrencyConverter::setEurPrice(const double eur) {
    eur_price = eur;
}

void CurrencyConverter::setAznPrice(const double azn) {
	azn_price = azn;
}

void CurrencyConverter::setGbpPrice(const double gbp) {
	gbp_price = gbp;
}