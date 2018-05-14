// Copyright 2018 Lalykin Oleg

#include "include/probability_distribution.h"
#include "include/prob_dis_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

ProbDisCalculator::ProbDisCalculator() : message_("") {}

void ProbDisCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a probability distribution calculator application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <z1_real> <z1_imaginary> " +
        "<z2_real> <z2_imaginary> <operation>\n\n" +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', '*', '/'.\n";
}


bool ProbDisCalculator::validateNumberOfArguments(int argc, const char** argv, int n) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (argc != 2 * n + 4) {
        help(argv[0], "ERROR: Should be nn3 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

unsigned char parseChar(const char* arg) {
    char* end;
    unsigned char value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}


char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "RawMoment") == 0) {
        op = '1';
    }
    else if (strcmp(arg, "CentralMoment") == 0) {
        op = '2';
    }
    else if (strcmp(arg, "Variance") == 0) {
        op = '3';
    }
    else if (strcmp(arg, "Expected") == 0) {
        op = '4';
    }
    else {
        throw std::string("Wrong operation format!");
    }
    return op;
}
std::string ProbDisCalculator::operator()(int argc, const char** argv) {

    Arguments args;
    args.n = parseDouble(argv[1]);
    if (!validateNumberOfArguments(argc, argv, args.n)) {
        return message_;
    }
    try {

        for (int i = 0; i < args.n; i++)
        {
            args.values.push_back(parseDouble(argv[i + 2]));
            args.probabilities.push_back(parseDouble(argv[i + 2 + args.n]));
        }
        args.operation = parseOperation(argv[2 * args.n + 2]);
        args.level = parseChar(argv[2 * args.n + 3]);
    }
    catch (std::string& str) {
        return str;
    }
    DescretePD dpd;

    unsigned char k = args.level;

    dpd.setData(args.values, args.probabilities);

    std::ostringstream stream;
    switch (args.operation) {
    case '1':
        stream << "RawMoment = " << dpd.rawMoment(k);        
        break;
    case '2':
        stream << "CentralMoment = " << dpd.centralMoment(k);
        break;
    case '3':
        stream << "Variance = " << dpd.variance();
        break;
    case '4':
        stream << "Expected = " << dpd.expectedValue();
        break;
    }

    message_ = stream.str();

    return message_;
}