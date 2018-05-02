/* Copyright 2018 TolyaTalamanov */

#ifndef MODULES_TEMPLATE_MAX_HEAP_INCLUDE_MAX_BINARY_HEAP_HPP_
#define MODULES_TEMPLATE_MAX_HEAP_INCLUDE_MAX_BINARY_HEAP_HPP_

#include <iterator>
#include <vector>
#include <algorithm>

using std::iter_swap;

template<class T>
class MaxBinaryHeap {
 public:
  MaxBinaryHeap() = default;
  explicit MaxBinaryHeap(int size_heap) { nodes.reserve(size_heap); }
  template<typename Iterator>
  MaxBinaryHeap(Iterator first, Iterator last) {
    std::copy(first, last, std::back_inserter(nodes));
    for (int i = nodes.size() / 2; i >= 0; --i) {
      shiftDown(i);
    }
  }
  MaxBinaryHeap(std::initializer_list<T> l)
  : MaxBinaryHeap(l.begin(), l.end()) {}
  void add(T value);
  std::size_t getHeapSize() { return nodes.size(); }
  bool empty() { return nodes.empty(); }
  T getMax();
  void deleteMax();
  T getElement(int i) { return nodes[i]; }

 private:
  void shiftUp(int node_index);
  void shiftDown(int node_index);

  int getLeftChild(int node_index);
  int getRightChild(int node_index);
  int getParrent(int node_index) { return (node_index - 1) / 2; }
  int getMaxChild(int node_index);

 private:
  std::vector<T> nodes;
};

template<class T>
void MaxBinaryHeap<T>::add(T value) {
  nodes.push_back(value);
  shiftUp(nodes.size() - 1);
}

template<class T>
T MaxBinaryHeap<T>::getMax() {
  if (empty()) {
    throw std::out_of_range("heap is empty");
  }
  return nodes.front();
}

template<class T>
void MaxBinaryHeap<T>::shiftUp(int node_index) {
  int parrent = getParrent(node_index);

  while (node_index > 0 && nodes[node_index] > nodes[parrent]) {
    iter_swap(nodes.begin() + node_index, nodes.begin() + parrent);
    node_index = parrent;
    parrent = getParrent(parrent);
  }
}

template<class T>
void MaxBinaryHeap<T>::shiftDown(int node_index) {
  int max_child_index = getMaxChild(node_index);

  while (max_child_index != -1 && nodes[node_index] < nodes[max_child_index]) {
    std::iter_swap(nodes.begin() + max_child_index, nodes.begin() + node_index);
    node_index = max_child_index;
    max_child_index = getMaxChild(max_child_index);
  }
}

template<class T>
int MaxBinaryHeap<T>::getLeftChild(int node_index) {
  int j = 2 * node_index + 1;

  if (j >= getHeapSize()) {
    j = -1;
  }

  return j;
}

template<class T>
int MaxBinaryHeap<T>::getRightChild(int node_index) {
  int j = getLeftChild(node_index);

  if (j != -1) {
    j = std::min<int>(j + 1, getHeapSize() - 1);
  }
  return j;
}

template<class T>
int MaxBinaryHeap<T>::getMaxChild(int node_index) {
  int left_child_index  = getLeftChild(node_index);
  int right_child_index = getRightChild(node_index);
  int max_child_index;

  if (left_child_index == -1) {
    max_child_index = -1;
  } else if (right_child_index != -1) {
    max_child_index = nodes[left_child_index] > nodes[right_child_index] ?
                      left_child_index : right_child_index;
  } else {
    max_child_index = left_child_index;
  }

  return max_child_index;
}

template<class T>
void MaxBinaryHeap<T>::deleteMax() {
  if (!empty()) {
    std::iter_swap(nodes.begin(), nodes.end() - 1);
    nodes.erase(nodes.end() - 1);
    shiftDown(0);
  }
}

#endif  // MODULES_TEMPLATE_MAX_HEAP_INCLUDE_MAX_BINARY_HEAP_HPP_
