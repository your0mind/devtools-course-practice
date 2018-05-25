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
        "\t-i       insert node in the tree\n" +
        "\t-f       find node in the tree\n" +
        "Examples: \n" +
        "\tapp -i 47\n" +
        "\tapp -f 47\n";
}

bool SearchTreeOptions::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        message_ = std::string("Usage:  search-tree-options.exe ") +
            "-[hif] [value]\n\n";
        return false;
    } else if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help("This is a search tree application.\n\n");
        return false;
    } else if (argc != 3) {
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

std::string SearchTreeOptions::operator()(int argc, const char** argv) {
    Arguments args;
    SearchTree tree;

    tree.Insert(47);
    tree.Insert(48);
    tree.Insert(46);
    tree.Insert(45);
    std::ostringstream stream;
    Tree * searchResulrt;
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.value = parseDouble(argv[2]);

        if (argv[1][0] == '-') {
                switch (argv[1][1]) {
                case('i'):
                    tree.Insert(args.value);
                    stream << "Insert was successful!" << tree.PrintTree();
                    break;
                case('f'):
                    searchResulrt = tree.Search(args.value);
                    if (searchResulrt == nullptr)
                        stream << "Tree hasn't node with this value.";
                    else
                        stream << "Search was successful! Found value: " +
                                    std::to_string((searchResulrt->value));
                    break;
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
