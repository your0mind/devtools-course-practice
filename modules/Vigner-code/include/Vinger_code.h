// Copyright 2018 Gusev Alexandr

#ifndef MODULES_VINGER_CODE_INCLUDE_VINGER_CODE_H_
#define MODULES_VINGER_CODE_INCLUDE_VINGER_CODE_H_
#include <iostream>
#include <string>

class Vinger_code {
public:
    Vinger_code();
    int Keycode(char s);
    std::string Encode(std::string Text, std::string Key);
    std::string Decode(std::string Text, std::string Key);
};

#endif  // MODULES_VINGER_CODE_INCLUDE_VINGER_CODE_H_