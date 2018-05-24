// Copyright 2018 Gladyshev Alexey

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/search_tree_options.h"
#include "include/search_tree.h"
#include <sstream>

int main(int argc, const char** argv) {
    SearchTreeOptions app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    /*std::ostringstream os;
    SearchTree tree;

    tree.Insert(47);
    tree.Insert(48);
    tree.Insert(46);
    tree.Insert(45);

    
    
    std::string output = tree.PrintTree();
    printf("%s\n", output.c_str());*/

    return 0;
}
