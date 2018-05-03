// Copyright 2018 Krasikova Ekaterina
#include "include/leftist_heap.h"
#include <queue>
leftist_heap::leftist_heap() {
    root = 0;
}
leftist_heap::leftist_heap(node *root_) {
    root = root_;
}
leftist_heap::leftist_heap(const leftist_heap& h) {
    if (h.root == 0) {
        root = 0;
        return;
    }
    std::queue<node*> q1, q2;
    q1.push(h.root);
    root = new node;
    q2.push(root);
    while (!q1.empty()) {
        node *tmp1, *tmp2;
        tmp1 = q1.front();
        q1.pop();
        tmp2 = q2.front();
        q2.pop();
        tmp2->key = tmp1->key;
        tmp2->rank = tmp1->rank;
        if (tmp1->left) {
            q1.push(tmp1->left);
            tmp2->left = new node;
            q2.push(tmp2->left);
        }
        if (tmp1->right) {
            q1.push(tmp1->right);
            tmp2->right = new node;
            q2.push(tmp2->right);
        }
    }
}
leftist_heap::~leftist_heap() {
    if (root == 0) {
        return;
    }
    std::queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node *tmp;
        tmp = q.front();
        q.pop();
        if (tmp->left) {
            q.push(tmp->left);
        }
        if (tmp->right) {
            q.push(tmp->right);
        }
        delete tmp;
    }
    root = 0;
}
leftist_heap& leftist_heap::operator=(const leftist_heap& h) {
    if (root == h.root) {
        return *this;
    }
    if (root != 0) {
        std::queue<node*> q;
        q.push(root);
        while (!q.empty()) {
            node *tmp;
            tmp = q.front();
            q.pop();
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
            delete tmp;
        }
    }
    leftist_heap *new_heap_pointer = new leftist_heap(h);
    root = new_heap_pointer->root;
    return *this;
}

void leftist_heap::merge(leftist_heap* h) {
    node *tmp;
    if (root == 0) {
        root = h->root;
        h->root = 0;
        return;
    }
    if (h->root == 0) {
        return;
    }
    if (root->key > h->root->key) {
        tmp = h->root;
        h->root = root;
        root = tmp;
    }
    leftist_heap right(root->right);
    right.merge(h);
    root->right = right.root;
    right.root = 0;
    if (root->left == 0 || root->right->rank > root->left->rank) {
        tmp = root->right;
        root->right = root->left;
        root->left = tmp;
    }
    if (root->right == 0) {
        root->rank = 1;
    } else {
        root->rank = root->left->rank < root->right->rank ?
            root->left->rank + 1 : root->right->rank + 1;
    }
    h->root = 0;
}
void leftist_heap::insert(int k) {
    node * new_node = new node;
    new_node->key = k;
    new_node->rank = 1;
    leftist_heap *new_heap = new leftist_heap(new_node);
    merge(new_heap);
}
int leftist_heap::MinKey() {
    if (root == 0) throw 1;
    return root->key;
}
void leftist_heap::DeleteMin() {
    if (root == 0) throw 1;
    leftist_heap left(root->left), *right = new leftist_heap(root->right);
    left.merge(right);
    root = left.root;
    left.root = 0;
}
