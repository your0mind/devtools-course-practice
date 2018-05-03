// Copyright 2018 Krasikova Ekaterina

#ifndef MODULES_LEFTIST_HEAP_INCLUDE_NODE_H_
#define MODULES_LEFTIST_HEAP_INCLUDE_NODE_H_

struct node {
    int key;
    int rank;
    node* parent;
    node* left;
    node* right;
    node() {
        key = 0;
        rank = 1;
        parent = left = right = 0;
    }
    explicit node(int k) {
        key = k;
        rank = 1;
        parent = left = right = 0;
    }
};
#endif  // MODULES_LEFTIST_HEAP_INCLUDE_NODE_H_
