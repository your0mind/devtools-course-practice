// Copyright 2018 Gorelova Ksenia

#include "include/search_tree.h"

SearchTree::SearchTree(Tree * pRoot) {
    this->pRoot = pRoot;
}

void SearchTree::AddTree(int val, Tree * pRoot) {
    if (pRoot == nullptr) {
        pRoot = new Tree;
        pRoot->value = val;
        pRoot->left = pRoot->right = nullptr;
        return;
    }
    if (val > pRoot->value)
        AddTree(val, pRoot->right);
    else
        AddTree(val, pRoot->left);
}

Tree * SearchTree::Search(Tree * pRoot, int key) {
    if (pRoot == nullptr)
        return nullptr;
    if (pRoot->value == key)
        return pRoot;
    if (key < pRoot->value)
        return Search(pRoot->left, key);
    else
        return Search(pRoot->right, key);
}

void SearchTree::DestroyBTree(Tree * pRoot) {
    if (pRoot != nullptr) {
        DestroyBTree(pRoot->left);
        DestroyBTree(pRoot->right);
        delete(pRoot);
    }
}
