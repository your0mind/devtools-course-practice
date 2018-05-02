/* Copyright 2018 TolyaTalamanov */

#ifndef MODULES_TEMPLATE_MAX_HEAP_INCLUDE_MAX_BINARY_HEAP_HPP_
#define MODULES_TEMPLATE_MAX_HEAP_INCLUDE_MAX_BINARY_HEAP_HPP_

#include <iterator>
#include <vector>
#include <algorithm>
#include <cstddef>

using std::size_t;

template<class T>
class MaxBinaryHeap {
 public:
  MaxBinaryHeap() = default;
  explicit MaxBinaryHeap(size_t size);
  MaxBinaryHeap(std::initializer_list<T> l);

  template<typename Iterator>
  MaxBinaryHeap(Iterator first, Iterator last) {
    std::copy(first, last, std::back_inserter(m_nodes));
    for (int i = m_nodes.size() / 2; i >= 0; --i) {
      shiftDown(i);
    }
  }

  void push(T value);
  size_t size();
  bool empty();
  T top();
  void pop();

 private:
  void shiftUp(int node_index);
  void shiftDown(int node_index);

  int getLeftChild(int node_index);
  int getRightChild(int node_index);
  int getParrent(int node_index);
  int getMaxChild(int node_index);

 private:
  std::vector<T> m_nodes;
};

template<class T>
inline
MaxBinaryHeap<T>::MaxBinaryHeap(size_t size) { m_nodes.reserve(size); }

template<class T>
inline
MaxBinaryHeap<T>::MaxBinaryHeap(std::initializer_list<T> l) :
                  MaxBinaryHeap(l.begin(), l.end()) {}

template<class T>
inline
size_t MaxBinaryHeap<T>::size() { return m_nodes.size(); }

template<class T>
inline
bool MaxBinaryHeap<T>::empty() { return m_nodes.empty(); }

template<class T>
void MaxBinaryHeap<T>::push(T value) {
  m_nodes.push_back(value);
  shiftUp(m_nodes.size() - 1);
}

template<class T>
T MaxBinaryHeap<T>::top() {
  if (empty()) {
    throw std::logic_error("heap is empty");
  }
  return m_nodes.front();
}

template<class T>
void MaxBinaryHeap<T>::shiftUp(int node_index) {
  int parrent = getParrent(node_index);

  while (node_index > 0 && m_nodes[node_index] > m_nodes[parrent]) {
    std::iter_swap(m_nodes.begin() + node_index, m_nodes.begin() + parrent);
    node_index = parrent;
    parrent = getParrent(parrent);
  }
}

template<class T>
void MaxBinaryHeap<T>::shiftDown(int node_index) {
  int max_child = getMaxChild(node_index);

  while (max_child != -1 && m_nodes[node_index] < m_nodes[max_child]) {
    std::iter_swap(m_nodes.begin() + max_child, m_nodes.begin() + node_index);
    node_index = max_child;
    max_child = getMaxChild(max_child);
  }
}

template<class T>
int MaxBinaryHeap<T>::getLeftChild(int node_index) {
  int j = 2 * node_index + 1;

  if (j >= size()) {
    j = -1;
  }

  return j;
}

template<class T>
int MaxBinaryHeap<T>::getRightChild(int node_index) {
  int j = getLeftChild(node_index);

  if (j != -1) {
    j = std::min<int>(j + 1, size() - 1);
  }
  return j;
}

template<class T>
inline
int MaxBinaryHeap<T>::getParrent(int node_index) {return (node_index - 1) / 2;}

template<class T>
int MaxBinaryHeap<T>::getMaxChild(int node_index) {
  int l_child  = getLeftChild(node_index);
  int r_child  = getRightChild(node_index);
  int max_child;

  if (l_child == -1) {
    max_child = -1;
  } else if (r_child != -1) {
    max_child = m_nodes[l_child] > m_nodes[r_child] ? l_child : r_child;
  } else {
    max_child = l_child;
  }

  return max_child;
}

template<class T>
void MaxBinaryHeap<T>::pop() {
  if (!empty()) {
    std::iter_swap(m_nodes.begin(), m_nodes.end() - 1);
    m_nodes.pop_back();
    shiftDown(0);
  }
}

#endif  // MODULES_TEMPLATE_MAX_HEAP_INCLUDE_MAX_BINARY_HEAP_HPP_
