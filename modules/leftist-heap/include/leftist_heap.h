// Copyright 2018 Krasikova Ekaterina

#pragma once
#include "Node.h"

class leftist_heap {
public:
    node *root;
    leftist_heap();
    leftist_heap(node *root_);
    leftist_heap(const leftist_heap& h);
    ~leftist_heap();
    leftist_heap& operator=(const leftist_heap& h);
    void merge(leftist_heap& h);
    void insert(int k);
    int MinKey();
    void DeleteMin();
};

