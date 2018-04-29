// Copyright 2018 Nifadyev Vadim

#include <gtest/gtest.h>
#include "include/length-converter.h"

TEST(LengthConverter, Can_Create_Length_Converter) {
    // Act & Assert
    ASSERT_NO_THROW(LengthConverter converter);
}

TEST(LengthConverter, Can_Convert_Centimeters_To_Meters) {
    // Arrange
    double centimeters = 1524;
    double expectedResult = 15.24;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.centimetersToMeters(centimeters),
                     expectedResult);
}

TEST(LengthConverter, Can_Convert_Meters_To_Centimeters) {
    // Arrange
    double meters = 21.56;
    double expectedResult = 2156;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.metersToCentimeters(meters), expectedResult);
}

TEST(LengthConverter, Throw_When_Trying_To_Convert_Negative_Measure_Unit) {
    // Arrange
    double centimeters = -1524;

    // Act
    LengthConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.centimetersToMeters(centimeters));
}

TEST(LengthConverter, Throw_When_Trying_To_Convert_Zero_Measure_Unit) {
    // Arrange
    double meters = 0;

    // Act
    LengthConverter converter;

    // Assert
    ASSERT_ANY_THROW(converter.metersToCentimeters(meters));
}

TEST(LengthConverter, Can_Convert_Meters_To_Kilometers) {
    // Arrange
    double meters = 678901;
    double expectedResult = 678.901;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.metersToKilometers(meters), expectedResult);
}

TEST(LengthConverter, Can_Convert_Kilometers_To_Meters) {
    // Arrange
    double kilometers = 0.48122;
    double expectedResult = 481.22;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.kilometersToMeters(kilometers), expectedResult);
}

TEST(LengthConverter, Can_Convert_Kilometers_To_Miles) {
    // Arrange
    double kilometers = 59.002;
    double expectedResult = 36.662143084387175;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.kilometersToMiles(kilometers), expectedResult);
}

TEST(LengthConverter, Can_Convert_Miles_To_Kilometers) {
    // Arrange
    double miles = 190.12;
    double expectedResult = 305.96848128;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.milesToKilometers(miles), expectedResult);
}

TEST(LengthConverter, Can_Convert_Foot_To_Yards) {
    // Arrange
    double foot = 8769123.055;
    double expectedResult = 2923041.0183333331;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.footToYards(foot), expectedResult);
}

TEST(LengthConverter, Can_Convert_Yards_To_Foot) {
    // Arrange
    double yards = 34.99124;
    double expectedResult = 104.97372;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.yardsToFoot(yards), expectedResult);
}

TEST(LengthConverter, Can_Convert_Foot_To_Meters) {
    // Arrange
    double foot = 4011.001;
    double expectedResult = 13159.452099737533;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.footToMeters(foot), expectedResult);
}

TEST(LengthConverter, Can_Convert_Meters_To_Foot) {
    // Arrange
    double meters = 12.333167;
    double expectedResult = 3.7591493016;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.metersToFoot(meters), expectedResult);
}

TEST(LengthConverter, Can_Convert_Centimeters_To_Inches) {
    // Arrange
    double centimeters = 11902.34;
    double expectedResult = 4685.9606299212601;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.centimetersToInches(centimeters),
                     expectedResult);
}

TEST(LengthConverter, Can_Convert_Inches_To_Centimeters) {
    // Arrange
    double inches = 674.53;
    double expectedResult = 1713.3062;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.inchesToCentimeters(inches), expectedResult);
}

TEST(LengthConverter, Can_Convert_Meters_To_Nautical_Miles) {
    // Arrange
    double meters = 32875.1211;
    double expectedResult = 17.751145302375807;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.metersToNauticalMiles(meters), expectedResult);
}

TEST(LengthConverter, Can_Convert_Nautical_Miles_To_Meters) {
    // Arrange
    double nauticalMiles = 3.00061;
    double expectedResult = 5557.12972;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.nauiticalMilesToMeters(nauticalMiles),
                     expectedResult);
}

TEST(LengthConverter, Can_Convert_Kilometers_To_Astronomical_Units) {
    // Arrange
    double kilometers = 8754875672001;
    double expectedResult = 58522.729174119195;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.kilometersToAstronomicalUnits(kilometers),
                     expectedResult);
}

TEST(LengthConverter, Can_Convert_Astronomical_Units_To_Kilometers) {
    // Arrange
    double astronomicalUnits = 2.1046;
    double expectedResult = 314843678.67522;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.astronomicalUnitsToKilometers(astronomicalUnits)
                     , expectedResult);
}

TEST(LengthConverter, Can_Convert_Centimeters_To_Spans) {
    // Arrange
    double centimeters = 5901.9;
    double expectedResult = 331.94038245219343;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.centimetersToSpans(centimeters),
                     expectedResult);
}

TEST(LengthConverter, Can_Convert_Spans_To_Centimeters) {
    // Arrange
    double spans = 712.014;
    double expectedResult = 12659.60892;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.spansToCentimeters(spans), expectedResult);
}

TEST(LengthConverter, Can_Convert_Spans_To_Versts) {
    // Arrange
    double spans = 38001.7125;
    double expectedResult = 6.33361875;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.spansToVersts(spans), expectedResult);
}

TEST(LengthConverter, Can_Convert_Versts_To_Spans) {
    // Arrange
    double versts = 14.077;
    double expectedResult = 84462;

    // Act
    LengthConverter converter;

    // Assert
    EXPECT_DOUBLE_EQ(converter.verstsToSpans(versts), expectedResult);
}
