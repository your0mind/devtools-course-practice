// Copyright 2018 Gorelova Ksenia

#include "include/search_tree.h"

SearchTree::SearchTree(Tree * pRoot) {
    this->pRoot = pRoot;
}

void SearchTree::AddTree(int val, Tree * tr) {
    if (tr == nullptr) {
        tr = new Tree;
        tr->value = val;
        tr->left = tr->right = nullptr;
        return;
    }
    if (val > tr->value)
        AddTree(val, tr->right);
    else
        AddTree(val, tr->left);
}

Tree * SearchTree::Search(Tree * tr, int key) {
    if (tr == nullptr)
        return nullptr;
    if (tr->value == key)
        return tr;
    if (key < tr->value)
        return Search(tr->left, key);
    else
        return Search(tr->right, key);
}

void SearchTree::DestroyBTree(Tree * tr) {
    if (tr != nullptr) {
        DestroyBTree(tr->left);
        DestroyBTree(tr->right);
        delete(tr);
    }
}
