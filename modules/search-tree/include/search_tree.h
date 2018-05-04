// Copyright 2018 Gorelova Ksenia

#ifndef MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_
#define MODULES_SEARCH_TREE_INCLUDE_SEARCH_TREE_H_

#include <iostream>

struct Node {
public:
    int key;
    int count;
    Node* left;
    Node* right;
};

class SearchTree
{
public:
    SearchTree(Node* pRoot = nullptr);
    ~SearchTree() {}
private:
    Node *pRoot;
    Node * AddNode(const int &num, Node *nd);
    int SearchNode(const int &num, Node *nd);
    Node * DelNode(Node * nd, Node * cur);
    Node * DelNode(Node * nd);
public:
    void Add(const int &num);
    int Search(const int &num);
    void DelTree(Node * nd);
    bool IsEmpty() const;
    Node * FindMin(Node * nd);
    Node * FindMax(Node * nd);
    Node * Find(Node *nd, const int &num);
};

#endif// MODULES_BINARY_SEARCH_INCLUDE_SEARCH_TREE_H_