// Copyright 2018 Novikova Alisa

#include <iostream>
#include <string>
#include "include/converter-numerical.h"


NumericalConverter::NumericalConverter() {
        InputNumber = 0;
        ArabicNumberOutput = 0;
        RomanNumeralOuput.clear();
}

std::string NumericalConverter::ConvertOneToRomanNumeral(int inNum) {
        while ((inNum -= 1) >= 0) {
                RomanNumeralOuput.append("I");
        }
        return RomanNumeralOuput;
}

std::string NumericalConverter::ConvertThreeToRomanNumeral(int inNum) {
        while ((inNum -= 1) >= 0) {
                RomanNumeralOuput.append("I");
        }
        return RomanNumeralOuput;
}

std::string NumericalConverter::ConvertToRomanNumeral(int inNum) {
        int m = 1000;
        int cm = 900;
        int d = 500;
        int cd = 400;
        int c = 100;
        int xc = 90;
        int l = 50;
        int xl = 40;
        int x = 10;
        int ix = 9;
        int v = 5;
        int iv = 4;
        int i = 1;
        while (inNum >= m) {
                RomanNumeralOuput.append("M");
                inNum -= m;
        }
        while (inNum >= cm) {
                RomanNumeralOuput.append("CM");
                inNum -= cm;
        }
        while (inNum >= d) {
                RomanNumeralOuput.append("D");
                inNum -= d;
        }
        while (inNum >= cd) {
                RomanNumeralOuput.append("CD");
                inNum -= cd;
        }
        while (inNum >= c) {
                RomanNumeralOuput.append("C");
                inNum -= c;
        }
        while (inNum >= xc) {
                RomanNumeralOuput.append("XC");
                inNum -= xc;
        }
        while (inNum>= l) {
                RomanNumeralOuput.append("L");
                inNum -= l;
        }
        while (inNum >= xl) {
                RomanNumeralOuput.append("XL");
                inNum -= xl;
        }
        while (inNum >= x) {
                RomanNumeralOuput.append("X");
                inNum -= x;
        }
        while (inNum >= ix) {
                RomanNumeralOuput.append("IX");
                inNum -= ix;
        }
        while (inNum >= v) {
                RomanNumeralOuput.append("V");
                inNum-= v;
        }
        while (inNum >= iv) {
                RomanNumeralOuput.append("IV");
                inNum -= m;
        }
        while (inNum >= i) {
                RomanNumeralOuput.append("I");
                inNum -= i;
        }
        return RomanNumeralOuput;
}

int NumericalConverter::ConvertOneToArabicNumber(std::string inStr) {
        if (inStr[0] == static_cast<char>('I')) {
                ArabicNumberOutput += 1;
        }
        return ArabicNumberOutput;
}

int NumericalConverter::ConvertRomanNumeralToArabicNumber(std::string inStr) {
        for (int i = 0; i < static_cast<int>(inStr.size()); ++i) {
                if (inStr[i + 1] == static_cast<char>('X')) {
                        ArabicNumberOutput += 9;
                        i++;
                } else if (inStr[i] == static_cast<char>('I')) {
                        ArabicNumberOutput += 1;
                }
        }
        return ArabicNumberOutput;
}

int NumericalConverter::ConvertRomanNumToArabicNumRefac(std::string inStr) {
    for (int i = 0; i <static_cast<int>(inStr.size()); ++i) {
        if (inStr[i] != inStr.back()) {
            if (inStr[i] == static_cast<char>('I')) {
                if (inStr[i + 1] != 'I') {
                    ArabicNumberOutput -= 1;
                }
                    // else {
                    // ArabicNumberOutput += 1;
                    // }
            }
            if (inStr[i] == static_cast<char>('V')) {
                ArabicNumberOutput += 5;
            }
            if (inStr[i] == static_cast<char>('X')) {
                if (inStr[i + 1] == 'I' || inStr[i + 1] == 'V') {
                    ArabicNumberOutput += 10;
                } else {
                    ArabicNumberOutput -= 10;
                }
            }
            if (inStr[i] == static_cast<char>('L')) {
                ArabicNumberOutput += 50;
            }
            if (inStr[i] == static_cast<char>('C')) {
                if (inStr[i + 1] == 'D' || inStr[i + 1] == 'M') {
                    ArabicNumberOutput -= 100;
                } else {
                    ArabicNumberOutput += 100;
                }
            }
            if (inStr[i] == static_cast<char>('D')) {
                ArabicNumberOutput += 500;
            }
            if (inStr[i] == static_cast<char>('M')) {
                ArabicNumberOutput += 1000;
            }
            } else {
            if (inStr[i] == static_cast<char>('I')) {
                ArabicNumberOutput += 1;
            }
            if (inStr[i] == static_cast<char>('V')) {
                ArabicNumberOutput += 5;
            }
            if (inStr[i] == static_cast<char>('X')) {
                ArabicNumberOutput += 10;
            }
            if (inStr[i] == static_cast<char>('L')) {
                ArabicNumberOutput += 50;
            }
            if (inStr[i] == static_cast<char>('C')) {
                ArabicNumberOutput += 100;
            }
            if (inStr[i] == static_cast<char>('D')) {
                ArabicNumberOutput += 500;
            }
            if (inStr[i] == static_cast<char>('M')) {
                ArabicNumberOutput += 1000;
            }
        }
    }
    return ArabicNumberOutput;
}
