// Copyright 2018 Grishin Anton

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/converter_numbers_in_words_app.h"

int main(int argc, const char** argv) {
    NumberInWords app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
