// Copyright 2018 Kamelina Julia

#ifndef MODULES_HUFFMAN_INCLUDE_HUFFMAN_H_
#define MODULES_HUFFMAN_INCLUDE_HUFFMAN_H_

#include <map>
#include <vector>

using std::map;
using std::vector;

struct CNode {
  CNode* left;
  CNode* right;
  char* value;
  char* code;
  int freq;

  CNode(char* v = 0, int f = 0,
        CNode* l = 0, CNode* r = 0, char* c = 0) {
    value = v;
    freq = f;
    left = l;
    right = r;
    code = c;
  }

  bool operator() (const CNode* x, const CNode* y) const {
    return (x->freq > y->freq) || ((x->freq == y->freq)
            && (static_cast<int>(x->value[0]) > static_cast<int>(y->value[0])));
  }
};

class Huffman {
 private:
    CNode* H_tree;
    vector<CNode*> frequency;

 private:
    void BuildTree();

 public:
    Huffman() {
      H_tree = nullptr;
    }
    explicit Huffman(char* text);
    ~Huffman();
    map<char, char*> Encode();
};

#endif  // MODULES_HUFFMAN_INCLUDE_HUFFMAN_H_
