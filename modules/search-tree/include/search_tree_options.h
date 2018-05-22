// Copyright 2018 Gladyshev Alexey

#ifndef MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_OPTIONS_H_
#define MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_OPTIONS_H_

#include <string>

class ComplexCalculator {
 public:
    ComplexCalculator();
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

#endif  // MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_OPTIONS_H_
