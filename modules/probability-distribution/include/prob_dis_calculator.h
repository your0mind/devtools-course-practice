// Copyright 2018 Lalykin Oleg

#ifndef MODULES_PROB_DIS_CALCULATOR_INCLUDE_PROB_DIS_CALCULATOR_H_
#define MODULES_PROB_DIS_CALCULATOR_INCLUDE_PROB_DIS_CALCULATOR_H_

#include <string>

class ProbDisCalculator {
public:
public:
	ProbDisCalculator();
	std::string operator()(int argc, const char** argv);

private:
	void help(const char* appname, const char* message = "");
	bool validateNumberOfArguments(int argc, const char** argv);
	std::string message_;
	typedef struct {
		double z1_real;
		double z1_imaginary;
		double z2_real;
		double z2_imaginary;
		char operation;
	} Arguments;
};

#endif  //MODULES_PROB_DIS_CALCULATOR_INCLUDE_PROB_DIS_CALCULATOR_H_
#pragma once
