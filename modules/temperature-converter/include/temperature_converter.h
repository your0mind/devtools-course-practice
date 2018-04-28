// Copyright 2018 Bederdinov Daniil

#ifndef MODULES_TEMPERATURE_CONVERTER_INCLUDE_COMPLEX_NUMBER_H_
#define MODULES_TEMPERATURE_CONVERTER_INCLUDE_COMPLEX_NUMBER_H_
#include <iostream>

class TemperatureConverter {
    public:
        TemperatureConverter() {}
        ~TemperatureConverter() {}

        double kelToCel(double);
        double kelToFahr(double);
        double kelToNewt(double);
        double celToKel(double);
        double celToFahr(double);
        double celToNewt(double);
        double fahrToCel(double);
        double fahrToKel(double);
        double fahrToNewt(double);
        double newtToCel(double);
        double newtToKel(double);
        double newtToFahr(double);
};

#endif  // MODULES_TEMPERATURE_CONVERTER_INCLUDE_COMPLEX_NUMBER_H_
