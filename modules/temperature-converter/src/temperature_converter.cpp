// Copyright 2018 Bederdinov Daniil

#include "include/temperature_converter.h"

double TemperatureConverter::kelToCel(double kel) {
    //kelvin = kel;
    return /*celsius =*/ kel - 273.15;
}

double TemperatureConverter::kelToFahr(double kel) {
    //kelvin = kel;
    return /*fahrenheit =*/ (9.0 / 5) * (kel - 273.15) + 32;
}

double TemperatureConverter::kelToNewt(double kel) {
    //kelvin = kel;
    return /*newton =*/ (kel - 273.15) * 0.33;
}

double TemperatureConverter::celToKel(double cel) {
    //celsius = cel;
    return /*kelvin =*/ cel + 273.15;
}

double TemperatureConverter::celToFahr(double cel) {
    //celsius = cel;
    return /*fahrenheit =*/ cel * (9.0 / 5) + 32;
}

double TemperatureConverter::celToNewt(double cel) {
    //celsius = cel;
    return /*newton =*/ cel * 0.33;
}

double TemperatureConverter::fahrToCel(double fahr) {
    //fahrenheit = fahr;
    return /*celsius =*/ (5.0 / 9) * (fahr - 32);
}

double TemperatureConverter::fahrToKel(double fahr) {
    //fahrenheit = fahr;
    return  /*kelvin =*/ (5.0 / 9) * (fahr - 32) + 273.15;
}

double TemperatureConverter::fahrToNewt(double fahr) {
    //fahrenheit = fahr;
    return /*newton =*/ (fahr - 32) * 0.183333;
}

double TemperatureConverter::newtToCel(double newt) {
    //newton = newt;
    return /*celsius =*/ newt * 3.030303;
}

double TemperatureConverter::newtToKel(double newt) {
    //newton = newt;
    return /*kelvin =*/ newt * 3.030303 + 273.15;
}

double TemperatureConverter::newtToFahr(double newt) {
    //newton = newt;
    return /*fahrenheit =*/ newt * 5.454545 + 32;
}
