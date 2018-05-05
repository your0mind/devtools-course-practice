/* Copyright 2018 TolyaTalamanov */

#ifndef MODULES_TEMPLATE_HEAP_INCLUDE_BINARY_HEAP_HPP_
#define MODULES_TEMPLATE_HEAP_INCLUDE_BINARY_HEAP_HPP_

#include <iterator>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <utility>
#include <functional>

using std::size_t;

template<class T,
         class Compare = std::greater<T>
         >

class BinaryHeap {
 public:
  BinaryHeap() = default;
  explicit BinaryHeap(size_t size) { m_nodes.reserve(size); }

  template<typename Iterator>
  BinaryHeap(Iterator first, Iterator last) : m_nodes(first, last) {
    for (int i = m_nodes.size() / 2; i >= 0; --i) {
      shiftDown(i);
    }
  }

  BinaryHeap(std::initializer_list<T> l) : BinaryHeap(l.begin(), l.end()) {}
  BinaryHeap(const BinaryHeap& other) : m_nodes(other.m_nodes) {}
  BinaryHeap(BinaryHeap&& other) : m_nodes(std::move(other.m_nodes)) {} // NOLINT

  void swap(BinaryHeap& other) noexcept { m_nodes.swap(other.m_nodes); }

  BinaryHeap& operator=(const BinaryHeap& other);
  BinaryHeap& operator=(BinaryHeap&& other); // NOLINT

  size_t size() { return m_nodes.size(); }
  bool empty() { return m_nodes.empty(); }

  void push(T value);
  void pop();
  T top();

  template<class ...Args>
  void emplace(Args&&... args) { // NOLINT
    m_nodes.emplace_back(std::forward<Args>(args)...);
    shiftUp(m_nodes.size() - 1);
  }

 private:
  void shiftUp(int node_index);
  void shiftDown(int node_index);

  int getLeftChild(int node_index);
  int getRightChild(int node_index);
  int getParrent(int node_index);
  int getMaxChild(int node_index);

 private:
  std::vector<T> m_nodes;
  Compare m_comp;
};

template<class T, class Compare>
BinaryHeap<T, Compare>&
BinaryHeap<T, Compare>::operator=(const BinaryHeap<T, Compare>& other) {
  if (this != &other) {
    BinaryHeap(other).swap(*this);
  }
  return *this;
}

template<class T, class Compare>
BinaryHeap<T, Compare>&
BinaryHeap<T, Compare>::operator=(BinaryHeap<T, Compare>&& other) { // NOLINT
  m_nodes = std::move(other.m_nodes);
  return *this;
}

template<class T, class Compare>
void BinaryHeap<T, Compare>::push(T value) {
  m_nodes.push_back(value);
  shiftUp(m_nodes.size() - 1);
}

template<class T, class Compare>
T BinaryHeap<T, Compare>::top() {
  if (empty()) {
    throw std::logic_error("heap is empty");
  }
  return m_nodes.front();
}

template<class T, class Compare>
void BinaryHeap<T, Compare>::shiftUp(int node_index) {
  int parrent = getParrent(node_index);

  while (node_index > 0 && m_comp(m_nodes[node_index],  m_nodes[parrent])) {
    std::iter_swap(m_nodes.begin() + node_index, m_nodes.begin() + parrent);
    node_index = parrent;
    parrent = getParrent(parrent);
  }
}

template<class T, class Compare>
void BinaryHeap<T, Compare>::shiftDown(int node_index) {
  int max_child = getMaxChild(node_index);

  while (max_child != -1 && !m_comp(m_nodes[node_index], m_nodes[max_child])) {
    std::iter_swap(m_nodes.begin() + max_child, m_nodes.begin() + node_index);
    node_index = max_child;
    max_child = getMaxChild(max_child);
  }
}

template<class T, class Compare>
int BinaryHeap<T, Compare>::getLeftChild(int node_index) {
  int j = 2 * node_index + 1;

  if (j >= size()) {
    j = -1;
  }

  return j;
}

template<class T, class Compare>
int BinaryHeap<T, Compare>::getRightChild(int node_index) {
  int j = getLeftChild(node_index);

  if (j != -1) {
    j = std::min<int>(j + 1, size() - 1);
  }
  return j;
}

template<class T, class Compare>
inline
int BinaryHeap<T, Compare>::getParrent(int node_index) {
  return (node_index - 1) / 2;
}

template<class T, class Compare>
int BinaryHeap<T, Compare>::getMaxChild(int node_index) {
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

template<class T, class Compare>
void BinaryHeap<T, Compare>::pop() {
  if (!empty()) {
    std::iter_swap(m_nodes.begin(), m_nodes.end() - 1);
    m_nodes.pop_back();
    shiftDown(0);
  }
}

#endif  // MODULES_TEMPLATE_HEAP_INCLUDE_BINARY_HEAP_HPP_
