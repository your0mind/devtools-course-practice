// Copyright 2018 Gladyshev Alexey

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/search_tree_options.h"

int main(int argc, const char** argv) {
    SearchTreeOptions app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
