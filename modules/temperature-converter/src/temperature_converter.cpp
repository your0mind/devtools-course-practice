// Copyright 2018 Bederdinov Daniil

#include "include/temperature_converter.h"

double TemperatureConverter::kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double TemperatureConverter::kelvinToFahrenheit(double kelvin) {
    return (9.0 / 5) * (kelvin - 273.15) + 32;
}

double TemperatureConverter::kelvinToNewton(double kelvin) {
    return (kelvin - 273.15) * 0.33;
}

double TemperatureConverter::celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double TemperatureConverter::celsiusToFahrenheit(double celsius) {
    return celsius * (9.0 / 5) + 32;
}

double TemperatureConverter::celsiusToNewton(double celsius) {
    return celsius * 0.33;
}

double TemperatureConverter::fahrenheitToCelsius(double fahrenheit) {
    return (5.0 / 9) * (fahrenheit - 32);
}

double TemperatureConverter::fahrenheitToKelvin(double fahrenheit) {
    return  (5.0 / 9) * (fahrenheit - 32) + 273.15;
}

double TemperatureConverter::fahrenheitToNewton(double fahrenheit) {
    return (fahrenheit - 32) * 0.183333;
}

double TemperatureConverter::newtonToCelsius(double newton) {
    return newton * 3.030303;
}

double TemperatureConverter::newtonToKelvin(double newton) {
    return newton * 3.030303 + 273.15;
}

double TemperatureConverter::newtonToFahrenheit(double newton) {
    return newton * 5.454545 + 32;
}
