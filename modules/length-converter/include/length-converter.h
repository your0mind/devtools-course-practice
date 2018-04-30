// Copyright 2018 Nifadyev Vadim

#include <iostream>
#include <string>

#ifndef MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
#define MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_

class LengthConverter {
 public:
    LengthConverter();
    ~LengthConverter();

    double centimetersToMeters(const double& centimeters) const;
    double metersToCentimeters(const double& meters) const;

    double metersToKilometers(const double& meters) const;
    double kilometersToMeters(const double& kilometers) const;

    double kilometersToMiles(const double& kilometers) const;
    double milesToKilometers(const double& miles) const;

    double footToYards(const double& foot) const;
    double yardsToFoot(const double& yards) const;

    double metersToFoot(const double& meters) const;
    double footToMeters(const double& foot) const;

    double centimetersToInches(const double& centimeters) const;
    double inchesToCentimeters(const double& inches) const;

    double metersToNauticalMiles(const double& meters) const;
    double nauiticalMilesToMeters(const double& nauticalMiles) const;

    double kilometersToAstronomicalUnits(const double& kilometers) const;
    double astronomicalUnitsToKilometers(const double& astronomicalUnit) const;

    double centimetersToSpans(const double& centimeters) const;
    double spansToCentimeters(const double& spans) const;

    double spansToVersts(const double& spans) const;
    double verstsToSpans(const double& versts) const;

 private:
     bool isCorrect(const double& value) const;
};

#endif  // MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
