// Copyright 2018 Lipatov Igor

#include <algorithm>

#ifndef DEVTOOLS_DHEAP_H
#define DEVTOOLS_DHEAP_H

#endif //DEVTOOLS_DHEAP_H

typedef std::pair<int, int> Vertex;

class Dheap {
public:
    Dheap(int d, int elemCount);
    bool isEmpty();
    Vertex pop();
    void push(Vertex v);
    void decreaseKey(int vNum, int lVal);
    int getVal(int vNum);
private:
    int elemCount;
    int d;
    std::vector<int> storage;  //vertex number
    std::vector<int> points; //(length,pos) [2 * vNum] indexing
    int key(int i);
    void swap(int iFir, int iSec);
    int up(int i);
    void del(int i);
    int down(int i);
    int minChail(int i);
};
