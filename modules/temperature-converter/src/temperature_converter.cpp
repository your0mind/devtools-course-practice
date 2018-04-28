// Copyright 2018 Bederdinov Daniil

#include "temperature_converter.h"

double TemperatureConverter::kelvinToCelsius(double kel) {
    return kel - 273.15;
}

double TemperatureConverter::kelvinToFahrenheit(double kel) {
    return (9.0 / 5) * (kel - 273.15) + 32;
}

double TemperatureConverter::kelvinToNewton(double kel) {
    return (kel - 273.15) * 0.33;
}

double TemperatureConverter::celsiusToKelvin(double cel) {
    return cel + 273.15;
}

double TemperatureConverter::celsiusToFahrenheit(double cel) {
    return cel * (9.0 / 5) + 32;
}

double TemperatureConverter::celsiusToNewton(double cel) {
    return cel * 0.33;
}

double TemperatureConverter::fahrenheitToCelsius(double fahr) {
    return (5.0 / 9) * (fahr - 32);
}

double TemperatureConverter::fahrenheitToKelvin(double fahr) {
    return  (5.0 / 9) * (fahr - 32) + 273.15;
}

double TemperatureConverter::fahrenheitToNewton(double fahr) {
    return (fahr - 32) * 0.183333;
}

double TemperatureConverter::newtonToCelsius(double newt) {
    return newt * 3.030303;
}

double TemperatureConverter::newtonToKelvin(double newt) {
    return newt * 3.030303 + 273.15;
}

double TemperatureConverter::newtonToFahrenheit(double newt) {
    return newt * 5.454545 + 32;
}
