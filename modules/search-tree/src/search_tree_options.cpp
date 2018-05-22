// Copyright 2018 Gladyshev Alexey

#include "include/search_tree.h"
#include "include/search_tree_options.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

SearchTreeOptions::SearchTreeOptions() : message_("") {}

void SearchTreeOptions::help(const std::string message) {
    message_ =
        message +
        "Usage:  search-tree-options.exe -[hif] [value]\n" +
        "\t-h       shows this help message\n" +
        "\t-i       insert node in the tree" +
        "\t-f       find node in the tree" +
        "Examples :\n" +
        "\ttopt -i 47\n" +
        "\ttopt -f 47\n";
}

bool SearchTreeOptions::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        message_ = std::string("Usage:  search-tree-options.exe ") +
            "-[hif] [value]\n";
        return false;
    }
    else if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help("This is a search tree application.");
        return false;
    }
    else if (argc != 3) {
        help(std::string("ERROR: Should be 2 arguments.\n\n"));
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
/*
char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}*/

std::string SearchTreeOptions::operator()(int argc, const char** argv) {
    Arguments args;
    std::ostringstream stream;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.value = parseDouble(argv[2]);
    
        SearchTree tree;

        if (argv[1][0] == '-') {
                switch (argv[1][1]) {
                case('i'):
                    tree.Insert(args.value);
                    break;
                case('f'):
                    tree.Search(args.value);
                    break;
                /*case('l'):
                    stream << "length 1_2 = " << T.Get_Length_side(first, second)
                        << std::endl
                        << "length 1_3 = " << T.Get_Length_side(first, third)
                        << std::endl
                        << "length 2_3 = " << T.Get_Length_side(second, third)
                        << std::endl;
                    break;
                case('a'):
                    stream << "angle 1 = " << T.Get_Angle(first)
                        << std::endl
                        << "angle 2 = " << T.Get_Angle(second)
                        << std::endl
                        << "angle 3 = " << T.Get_Angle(third)
                        << std::endl;
                    break;
                case('r'):
                    stream << "Radius Inscribed Circle = "
                        << T.Get_Radius_Of_Inscribed_Circle() << std::endl;
                    break;
                case('R'):
                    stream << "Radius Circumscribed Circle = "
                        << T.Get_Radius_Of_Circumscribed_Circle() << std::endl;
                    break;
                case('s'):
                    stream << "Square = " << T.Get_Square() << std::endl;
                    break;
                case('p'):
                    stream << "Perimeter = " << T.Get_Perimeter() << std::endl;
                    break;
                case('b'):
                    A = T.Get_Barycenter();
                    stream << "Barycenter = <"
                        << A.x << ", " << A.y << ">" << std::endl;
                    A = T.Get_Center_Of_Inscribed_Circle();
                    break;
                case('c'):
                    A = T.Get_Center_Of_Inscribed_Circle();
                    stream << "Center Inscribed Circle = <"
                        << A.x << ", " << A.y << ">" << std::endl;
                    break;*/
                default:
                    help(std::string("Unknown option ") + argv[1] + "\n\n");
                    return message_;
                }
            } else {
                help();
                return message_;
            }
    }
    catch (std::string& str) {
        return str;
    }

    message_ = stream.str();

    return message_;
}
