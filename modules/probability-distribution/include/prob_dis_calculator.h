// Copyright 2018 Lalykin Oleg

#ifndef MODULES_PROB_DIS_CALCULATOR_INCLUDE_PROB_DIS_CALCULATOR_H_
#define MODULES_PROB_DIS_CALCULATOR_INCLUDE_PROB_DIS_CALCULATOR_H_

#include <string>
#include <vector>

class ProbDisCalculator {
 public:
    ProbDisCalculator();
    std::string operator()(int argc, const char** argv);

    
 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv,int n);
    std::string message_;
    typedef struct {
        int n;
        std::vector<double> values ;
        std::vector<double> probabilities ;
        char operation;
        unsigned char level;
    } Arguments;

};

#endif  // MODULES_PROB_DIS_CALCULATOR_INCLUDE_PROB_DIS_CALCULATOR_H_
