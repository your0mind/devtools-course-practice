// Copyright 2018 Gorelova Ksenia

#include "include/search_tree.h"

void SearchTree::AddTree(int val, Tree ** tr) {
    if (*tr == nullptr) {
        (*tr) = new Tree;
        (*tr)->value = val;
        (*tr)->left = (*tr)->right = nullptr;
        return;
    }
    if (val > (*tr)->value)
        AddTree(val, &(*tr)->right);
    else
        AddTree(val, &(*tr)->left);
}

Tree * SearchTree::FindMin(Tree * tr) {
    if (tr->left != nullptr) {
        return FindMin(tr->left);
    }
    else {
        return tr;
    }
}

Tree * SearchTree::FindMax(Tree * tr) {
    if (tr->right != nullptr) {
        return  FindMax(tr->right);
    }
    else {
        return tr;
    }
}

int SearchTree::NumberOfNodes(Tree * tr) {
    if (tr == nullptr)
        return 0;
    return NumberOfNodes(tr->left) + 1 + NumberOfNodes(tr->right);
}

int SearchTree::ListCount(Tree * nd) {
    if (!nd)
        return 0;
    if (!nd->left && !nd->right)
        return 1;
    return  ListCount(nd->left) + ListCount(nd->right);
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
