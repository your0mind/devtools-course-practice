// Copyright 2018 Zinoviev Vladimir

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/Triangles.h"
#include "include/triangle-options.h"

TriangleOptions::TriangleOptions() : message_("") {}

void TriangleOptions::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a triangle options application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <x_1> <y_1> " +
          "<x_2> <y_2> <x_3> <y_3> <option>\n\n" +

          "  Where all arguments are double-precision numbers, " +
          "and <option> is one of \n" +
          "'Lengths', \n" +
          "'Angles', \n" +
          "'Radius_Inscribed', \n" +
          "'Radius_Circumscribed', \n" +
          "'Square', \n" +
          "'Perimeter', \n" +
          "'Barycenter', \n" +
          "'Center_Inscribed'.\n" +
          "Without <options> program will be output all options";
}

bool TriangleOptions::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 7 && argc != 8) {
        help(argv[0], "ERROR: Should be 7 or 8 arguments.\n\n");
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

Option parseOption(const char* arg) {
    Option op;
    if (strcmp(arg, "Lengths") == 0) {
        op = Lengths;
    } else if (strcmp(arg, "Angles") == 0) {
        op = Angles;
    } else if (strcmp(arg, "Radius_Inscribed") == 0) {
        op = Radius_Inscribed;
    } else if (strcmp(arg, "Radius_Circumscribed") == 0) {
        op = Radius_Circumscribed;
    } else if (strcmp(arg, "Square") == 0) {
        op = Square;
    } else if (strcmp(arg, "Perimeter") == 0) {
        op = Perimeter;
    } else if (strcmp(arg, "Barycenter") == 0) {
        op = Barycenter;
    } else if (strcmp(arg, "Center_Inscribed") == 0) {
        op = Center_Inscribed;
    } else {
        throw std::string("Wrong option format!");
    }
    return op;
}

std::string TriangleOptions::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.x_1    = parseDouble(argv[1]);
        args.y_1    = parseDouble(argv[2]);
        args.x_2    = parseDouble(argv[3]);
        args.y_2    = parseDouble(argv[4]);
        args.x_3    = parseDouble(argv[5]);
        args.y_3    = parseDouble(argv[6]);
        if (argc == 8)
            args.option = parseOption(argv[7]);
    }
    catch(std::string& str) {
        return str;
    }

    Triangles T(
        Vertex(args.x_1, args.y_1),
        Vertex(args.x_2, args.y_2),
        Vertex(args.x_3, args.y_3));

    std::ostringstream stream;

    if (argc == 7) {
        stream << "length 1_2 = " << T.Get_Length_side(first, second)
            << std::endl
            << "length 1_3 = " << T.Get_Length_side(first, third)
            << std::endl
            << "length 2_3 = " << T.Get_Length_side(second, third)
            << std::endl;
        stream << "angle 1 = " << T.Get_Angle(first)
            << std::endl
            << "angle 2 = " << T.Get_Angle(second)
            << std::endl
            << "angle 3 = " << T.Get_Angle(third)
            << std::endl;
        stream << "Radius Inscribed Circle = "
            << T.Get_Radius_Of_Inscribed_Circle() << std::endl;
        stream << "Radius Circumscribed Circle = "
            << T.Get_Radius_Of_Circumscribed_Circle() << std::endl;
        stream << "Square = " << T.Get_Square() << std::endl;
        stream << "Perimeter = " << T.Get_Perimeter() << std::endl;
        Vertex A = T.Get_Barycenter();
        stream << "Barycenter = <"
            << A.x << ", " << A.y << ">" << std::endl;
        A = T.Get_Center_Of_Inscribed_Circle();
        stream << "Center Inscribed Circle = <"
            << A.x << ", " << A.y << ">" << std::endl;
    } else {
        Vertex A;
        switch (args.option) {
        case Lengths:
            stream << "length 1_2 = " << T.Get_Length_side(first, second)
                << std::endl
                << "length 1_3 = " << T.Get_Length_side(first, third)
                << std::endl
                << "length 2_3 = " << T.Get_Length_side(second, third)
                << std::endl;
            break;
        case Angles:
            stream << "angle 1 = " << T.Get_Angle(first)
                << std::endl
                << "angle 2 = " << T.Get_Angle(second)
                << std::endl
                << "angle 3 = " << T.Get_Angle(third)
                << std::endl;
            break;
        case Radius_Inscribed:
            stream << "Radius Inscribed Circle = "
                << T.Get_Radius_Of_Inscribed_Circle() << std::endl;
            break;
        case Radius_Circumscribed:
            stream << "Radius Circumscribed Circle = "
                << T.Get_Radius_Of_Circumscribed_Circle() << std::endl;
            break;
        case Square:
            stream << "Square = " << T.Get_Square() << std::endl;
            break;
        case Perimeter:
            stream << "Perimeter = " << T.Get_Perimeter() << std::endl;
            break;
        case Barycenter:
            A = T.Get_Barycenter();
            stream << "Barycenter = <"
                << A.x << ", " << A.y << ">" << std::endl;
            A = T.Get_Center_Of_Inscribed_Circle();
            break;
        case Center_Inscribed:
            A = T.Get_Center_Of_Inscribed_Circle();
            stream << "Center Inscribed Circle = <"
                << A.x << ", " << A.y << ">" << std::endl;
        }
    }

    message_ = stream.str();

    return message_;
}
