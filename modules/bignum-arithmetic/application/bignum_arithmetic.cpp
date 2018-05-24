// Copyright 2018 Usova Marina

#include <cstdlib>
#include <cstdio>
#include <string>

#include "include/bignum_calculator.h"

int main(int argc, const char** argv) {
    BigNumCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
