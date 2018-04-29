// Copyright 2018 Nifadyev Vadim

#include "include\length-converter.h"

LengthConverter::LengthConverter() { }

LengthConverter::~LengthConverter() { }

double LengthConverter::centimetersToMeters(double centimeters) {
    if (isCorrect(centimeters)) {
        return centimeters / 100;
    }
}

double LengthConverter::metersToCentimeters(double meters) {
    if (isCorrect(meters)) {
        return meters * 100;
    }
}

double LengthConverter::metersToKilometers(double meters) {
    if (isCorrect(meters)) {
        return meters / 1000;
    }
}

double LengthConverter::kilometersToMeters(double kilometers) {
    if (isCorrect(kilometers)) {
        return kilometers * 1000;
    }
}

double LengthConverter::kilometersToMiles(double kilometers) {
    if (isCorrect(kilometers)) {
        return kilometers / 1.609344;
    }
}

double LengthConverter::milesToKilometers(double miles) {
    if (isCorrect(miles)) {
        return miles * 1.609344;
    }
}

double LengthConverter::footToYards(double foot) {
    if (isCorrect(foot)) {
        return foot / 3;
    }
}

double LengthConverter::yardsToFoot(double yards) {
    if (isCorrect(yards)) {
        return yards * 3;
    }
}

double LengthConverter::footToMeters(double foot) {
    if (isCorrect(foot)) {
        return foot / 0.3048;
    }
}

double LengthConverter::metersToFoot(double meters) {
    if (isCorrect(meters)) {
        return meters * 0.3048;
    }
}

double LengthConverter::centimetersToInches(double centimeters) {
    if (isCorrect(centimeters)) {
        return centimeters / 2.54;
    }
}

double LengthConverter::inchesToCentimeters(double inches) {
    if (isCorrect(inches)) {
        return inches * 2.54;
    }
}

double LengthConverter::metersToNauticalMiles(double meters) {
    if (isCorrect(meters)) {
        return meters / 1'852;
    }
}

double LengthConverter::nauiticalMilesToMeters(double nauticalMiles) {
    if (isCorrect(nauticalMiles)) {
        return nauticalMiles * 1'852;
    };
}

double LengthConverter::kilometersToAstronomicalUnits(double kilometers) {
    if (isCorrect(kilometers)) {
        return kilometers / 149'597'870.7;
    };
}

double LengthConverter::astronomicalUnitsToKilometers(double astronomicalUnits) {
    if (isCorrect(astronomicalUnits)) {
        return astronomicalUnits * 149'597'870.7;
    };
}

double LengthConverter::centimetersToSpans(double centimeters) {
    if (isCorrect(centimeters)) {
        return centimeters / 17.78;
    };
}

double LengthConverter::spansToCentimeters(double spans) {
    if (isCorrect(spans)) {
        return spans * 17.78;
    };
}

double LengthConverter::spansToVersts(double spans) {
    if (isCorrect(spans)) {
        return spans / 6'000;
    };
}

double LengthConverter::verstsToSpans(double versts) {
    if (isCorrect(versts)) {
        return versts * 6'000;
    };
}

bool LengthConverter::isCorrect(double value) {
    const double eps = 0.01;
    if (value < eps && value > -eps) {
        throw "Error! Measure unit cannot be 0";
    }
    if (value < 0) {
        throw "Error! Measure unit must be positive";
    }
    return true;
}
