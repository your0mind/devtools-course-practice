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
    explicit SearchTree(Tree * pRoot = nullptr);
    Tree * pRoot;
    void AddTree(int val, Tree * tr);
    Tree * Search(Tree * tr, int key);
    void DestroyBTree(Tree * tr);
};

#endif   // MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
