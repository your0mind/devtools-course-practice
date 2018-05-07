// Copyright 2018 Gorelova Ksenia

#ifndef MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
#define MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_

struct Tree {
 public:
    int value;
    Tree * left;
    Tree * right;
};

class SearchTree {
 public:
    void AddTree(int val, Tree** tr);
    Tree * FindMin(Tree * tr);
    Tree * FindMax(Tree * tr);
    int NumberOfNodes(Tree* tr);
    int ListCount(Tree* nd);
    Tree * Search(Tree * tr, int key);
    void DestroyBTree(Tree * tr);
};

#endif   // MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
