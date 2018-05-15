// Copyright 2018 Bederdinov Daniil

#include "include/temperature_converter.h"


TemperatureConverter::TemperatureConverter(double current_temperature_ = 0,
    char current_scale_ = 'C') {
    current_temperature = current_temperature_;
    if (current_scale_ == 'C' || current_scale_ == 'K' || current_scale_ == 'F' || current_scale_ == 'N')
        current_scale = current_scale_;
    else
        throw ("Incorrect temperature scale");
}

double TemperatureConverter::getCurrentTemperature() {
    return this->current_temperature;
}

void TemperatureConverter::setCurrentTemperature(double current_temperature_) {
    current_temperature = current_temperature_;
}

TemperatureConverter TemperatureConverter::convert(TemperatureConverter temperature, char new_scale) {
    TemperatureConverter temp = temperature;
    if(temperature.current_scale=='K') {
        switch (new_scale) {
            case 'C':
                temperature.current_temperature -= 273.15;
                break;
            case 'F':
                temperature.current_temperature = (9.0 / 5) * (temperature.current_temperature - 273.15) + 32;
                break;
            case 'N':
                temperature.current_temperature = (temperature.current_temperature - 273.15) * 0.33;
                break;
            default:
                throw ("Incorrect new temperature scale");
            break;
        }
        temperature.current_scale = new_scale;
        return temperature;
    }
    else if (temperature.current_scale == 'C') {
        switch (new_scale)
        {
        case 'K':
            temperature.current_temperature += 273.15;
            break;
        case 'F':
            temperature.current_temperature = temperature.current_temperature * (9.0 / 5) + 32;
            break;
        case 'N':
            temperature.current_temperature = temperature.current_temperature * 0.33;
            break;
        default:
            throw ("Incorrect new temperature scale");
            break;
        }
        temperature.current_scale = new_scale;
        return temperature;
    }
    else if (temperature.current_scale == 'F') {
        switch (new_scale)
        {
        case 'K':
            temperature.current_temperature = (5.0 / 9) * (temperature.current_temperature - 32) + 273.15;
            break;
        case 'C':
            temperature.current_temperature = (5.0 / 9) * (temperature.current_temperature - 32);
            break;
        case 'N':
            temperature.current_temperature = (temperature.current_temperature - 32) * 0.183333;
            break;
        default:
            throw ("Incorrect new temperature scale");
            break;
        }
        temperature.current_scale = new_scale;
        return temperature;
    }
    else if (temperature.current_scale == 'N') {
        switch (new_scale)
        {
        case 'K':
            temperature.current_temperature = temperature.current_temperature * 3.030303 + 273.15;
            break;
        case 'C':
            temperature.current_temperature *= 3.030303;
            break;
        case 'F':
            temperature.current_temperature = temperature.current_temperature * 5.454545 + 32;
            break;
        default:
            throw ("Incorrect new temperature scale");
            break;
        }
        temperature.current_scale = new_scale;
        return temperature;
    }
}

//double TemperatureConverter::kelvinToCelsius(double kelvin) {
//    return kelvin - 273.15;
//}
//
//double TemperatureConverter::kelvinToFahrenheit(double kelvin) {
//    return (9.0 / 5) * (kelvin - 273.15) + 32;
//}
//
//double TemperatureConverter::kelvinToNewton(double kelvin) {
//    return (kelvin - 273.15) * 0.33;
//}
//
//double TemperatureConverter::celsiusToKelvin(double celsius) {
//    return celsius + 273.15;
//}
//
//double TemperatureConverter::celsiusToFahrenheit(double celsius) {
//    return celsius * (9.0 / 5) + 32;
//}
//
//double TemperatureConverter::celsiusToNewton(double celsius) {
//    return celsius * 0.33;
//}
//
//double TemperatureConverter::fahrenheitToCelsius(double fahrenheit) {
//    return (5.0 / 9) * (fahrenheit - 32);
//}
//
//double TemperatureConverter::fahrenheitToKelvin(double fahrenheit) {
//    return  (5.0 / 9) * (fahrenheit - 32) + 273.15;
//}
//
//double TemperatureConverter::fahrenheitToNewton(double fahrenheit) {
//    return (fahrenheit - 32) * 0.183333;
//}
//
//double TemperatureConverter::newtonToCelsius(double newton) {
//    return newton * 3.030303;
//}
//
//double TemperatureConverter::newtonToKelvin(double newton) {
//    return newton * 3.030303 + 273.15;
//}
//
//double TemperatureConverter::newtonToFahrenheit(double newton) {
//    return newton * 5.454545 + 32;
//}
