// Copyright 2018 Gusev Alexandr

#include <iostream>
#include <string>
using namespace std;
class Vinger_code
{
public:
    Vinger_code();
    ~Vinger_code();
    int Keycode(char s);
    string Encode(string Text, string Key);
    string Decode(string Text, string Key);
};