// Copyright 2018 Zinoviev Vladimir

#ifndef MODULES_TRIANGLE_OPTIONS_INCLUDE_TRIANGLE_OPTIONS_H_
#define MODULES_TRIANGLE_OPTIONS_INCLUDE_TRIANGLE_OPTIONS_H_

#include <string>

typedef enum {
    Lengths,
    Angles,
    Radius_Inscribed,
    Radius_Circumscribed,
    Square,
    Perimeter,
    Barycenter,
    Center_Inscribed
} Option;

class TriangleOptions {
 public:
     TriangleOptions();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double x_1;
        double y_1;
        double x_2;
        double y_2;
        double x_3;
        double y_3;
        Option option;
    } Arguments;
};

#endif  // MODULES_TRIANGLE_OPTIONS_INCLUDE_TRIANGLE_OPTIONS_H_
