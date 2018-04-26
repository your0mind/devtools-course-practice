// Copyright 2018 Nifadyev Vadim

#include <iostream>
#include <string>

#ifndef LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
#define LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_

class LengthConverter {
 public:
    LengthConverter();
    ~LengthConverter();

    void input();
    void menu();

    double centimetersToMeters(const double &centimeters);
    double metersToCentimeters(const double &meters);

    double metersToKilometers(const double &meters);
    double kilometersTometers(const double &kilometers);

    double kilometersToMiles(const double &kilometers);
    double milesToKilometers(const double &miles);

    double milesToYards(const double &miles);
    double yardsToMiles(const double &yards);

    double milesToFoot(const double &miles);
    double footToMiles(const double &foot);

    double milesToInches(const double &miles);
    double inchesToMiles(const double &inches);

    double metersToNauticalMiles(const double &meters);
    double nauiticalMilesToMeters(const double &nauticalMiles);

    double metersToAstronomicalUnits(const double &meters);
    double astronomicalUnitsToMeters(const double &astronomicalUnits);

    double metersToSpans(const double &meters);
    double spansToMeters(const double &spans);  // Span - old russian metric

    double spansToVersts(const double &spans);
    double verstsToSpans(const double &versts);

 private:
    std::string input;
};


#endif  // LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
