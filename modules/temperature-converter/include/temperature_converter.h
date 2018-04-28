// Copyright 2018 Bederdinov Daniil

#ifndef MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
#define MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_

class TemperatureConverter {
 public:
  TemperatureConverter() {}
  ~TemperatureConverter() {}

  double kelvinToCelsius(double kelvin);
  double kelvinToFahrenheit(double kelvin);
  double kelvinToNewton(double kelvin);
  double celsiusToKelvin(double celsius);
  double celsiusToFahrenheit(double celsius);
  double celsiusToNewton(double celsius);
  double fahrenheitToCelsius(double fahrenheit);
  double fahrenheitToKelvin(double fahrenheit);
  double fahrenheitToNewton(double fahrenheit);
  double newtonToCelsius(double newton);
  double newtonToKelvin(double newton);
  double newtonToFahrenheit(double newton);
};

#endif  // MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
