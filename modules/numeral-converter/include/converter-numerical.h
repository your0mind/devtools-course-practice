// Copyright 2018 Novikova Alisa
#ifndef MODULES_NUMERICAL_CONVERTER_INCLUDE_NUMERICAL_CONVERTER_H_
#define MODULES_NUMERICAL_CONVERTER_INCLUDE_NUMERICAL_CONVERTER_H_
#include <iostream>
#include <cstring>
using namespace std;

class NumericalConverter
{
public:

	int InputNumber;
	int ArabicNumberOutput;

	string RomanNumeralOuput;

	//Constructor
	NumericalConverter();

	// Functions to convert from Arabic numbers to Roman Numeral
	string ConvertOneToRomanNumeral(int inputNumber);
	string ConvertThreeToRomanNumeral(int inputNumber);
	string ConvertToRomanNumeral(int inputNumber);

	// Functions to convert from Roman Numeral to Arabic numbers
	int ConvertOneToArabicNumber(string inputString);
	int ConvertRomanNumeralToArabicNumber(string inputString);
	int ConvertRomanNumeralToArabicNumberRefactored(string inputString);
};

#endif  MODULES_TEMPERATURE_CONVERTER_INCLUDE_NUMERICAL_CONVERTER_H_