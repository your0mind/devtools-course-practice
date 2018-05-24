// Copyright 2018 Fedorova Olga

#include "include/interp_search.h"
#include "include/interp_search_app.h"

#include <stdlib.h>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

InterpSearchApp::InterpSearchApp() {
    msg = "";
}

bool InterpSearchApp::AreArgumentsValid(int argc, const char** argv) {
    if (argc == 1) {
       msg = std::string("Input following arguments:\n") +
               "list of integers and number," +
               "which possition you want to find there.\n";
       return false;
    } else if (argc < 3) {
        msg = std::string("There should be 2 arguments:\n") +
                          "list of integers and number," +
                          "which possition you want to find there.\n";
        return false;
    }

    return true;
}

int MyToInt(const char* arg) {
    char* end = 0;
    int64_t value = strtol(arg, &end, 10);
    if (end[0] != 0 ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max()) {
        throw std::string("ERROR: Wrong number format! ") + arg;
    }

    return static_cast<int>(value);
}

std::string InterpSearchApp::operator()(int argc, const char** argv) {
    if (!AreArgumentsValid(argc, argv)) {
         return msg;
    }

    int value;
    int length = argc - 2;
    std::vector<int> vect(length);
    try {
       for (int i = 0; i < length ; i++)
            vect[i] = MyToInt(argv[i+1]);

        value = MyToInt(argv[length+1]);
    }
    catch (std::string& str) {
        return str;
    }

    int result = xab::interpSearch(vect, value);
    if (result == -1)
        msg = "Element " + std::to_string(value) + " hasn't been found.\n";
    else
        msg = "Element " + std::to_string(value) + " is at "
               + std::to_string(result) + " place.\n";

    return msg;
}
