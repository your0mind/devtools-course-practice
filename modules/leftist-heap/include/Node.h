// Copyright 2018 Krasikova Ekaterina

#pragma once

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
    node(int k) {
        key = k;
        rank = 1;
        parent = left = right = 0;
    }
};