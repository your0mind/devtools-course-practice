// Copyright 2018 Bederdinov Daniil

#ifndef MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
#define MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_

class TemperatureConverter {
 public:
  TemperatureConverter(double current_temperature_ = 0,
       char current_scale_ = 'C');
  TemperatureConverter(TemperatureConverter temp);
  ~TemperatureConverter() {}

  TemperatureConverter convert(TemperatureConverter temperature,
      char new_scale);
  double getCurrentTemperature();
  // void setCurrentTemperature(double current_temperature_);

 private:
  double current_temperature;
  char current_scale;
};

#endif  // MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
