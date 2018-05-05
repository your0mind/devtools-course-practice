/* Copyright 2018 TolyaTalamanov */

#include <gtest/gtest.h>
#include <vector>
#include "include/binary_heap.hpp"

TEST(BinaryHeapTest, Can_Create_Empty_Heap) {
  // AAA
  ASSERT_NO_THROW(BinaryHeap<int> heap);
}

TEST(BinaryHeapTest, Can_Create_Heap_With_Reserved_Memory) {
  // AAA
  ASSERT_NO_THROW(BinaryHeap<int> heap(100));
}

TEST(BinaryHeapTest, Can_Create_Heap_From_Initializer_List) {
  // AAA
  ASSERT_NO_THROW(BinaryHeap<int> heap{1});
}

TEST(BinaryHeapTest, Can_Create_Heap_From_Vector) {
  // Arrange
  std::vector<int> v {1, 4, -3, 2};

  // Act & Assert
  ASSERT_NO_THROW(BinaryHeap<int> heap(v.begin(), v.end()));
}

TEST(BinaryHeapTest, Check_That_Empty_Heap_Is_Empty) {
  // Arrange
  BinaryHeap<int> heap;

  // Act & Assert
  ASSERT_TRUE(heap.empty());
}

TEST(BinaryHeapTest, Check_Heap_Size) {
  // Arrange
  BinaryHeap<int> heap;

  // Act
  for (int i = 0; i < 100; ++i) {
    heap.push(i);
  }

  // Assert
  EXPECT_EQ(100, heap.size());
}

TEST(BinaryHeapTest, Right_Push_Element) {
  // Arrange
  BinaryHeap<int> heap = {1, 3, 5};

  // Act
  heap.push(1000);

  // Assert
  EXPECT_EQ(1000, heap.top());
}

TEST(BinaryHeapTest, Right_Emplace_Element) {
  // Arrange
  BinaryHeap<int> heap = {1, 3, 5};

  // Act
  heap.emplace(1000);

  // Assert
  EXPECT_EQ(1000, heap.top());
}

TEST(BinaryHeapTest, Throw_When_Get_Top_From_Empty_Heap) {
  // Arrange
  BinaryHeap<int> heap;

  // Act & Assert
  ASSERT_ANY_THROW(heap.top());
}

TEST(BinaryHeapTest, Check_Get_Top) {
  // Arrange
  BinaryHeap<int> heap;

  // Act
  for (int i = 0; i < 4; ++i) {
    heap.push(i);
  }

  // Assert
  EXPECT_EQ(3, heap.top());
}

TEST(BinaryHeapTest, Can_Create_Copy_Heap) {
  // Arrange
  BinaryHeap<int> h {2, -5, 1, 2};

  // Act
  BinaryHeap<int> ch(h);

  // Assert
  EXPECT_EQ(2, ch.top());
}

TEST(BinaryHeapTest, Check_Swap_Heaps) {
  // Arrange
  BinaryHeap<int> h1 {2, -5, 1, 2};
  BinaryHeap<int> h2 {100, 1000, 3};

  // Act
  h1.swap(h2);

  // Assert
  EXPECT_EQ(1000, h1.top());
  EXPECT_EQ(2, h2.top());
}

TEST(BinaryHeapTest, Check_Assignment_Operator) {
  // Arrange
  BinaryHeap<int> h1 {2, -5, 1, 2};
  BinaryHeap<int> h2 {100, 1000, 3};

  // Act
  h1 = h2;
  // Assert
  EXPECT_EQ(1000, h1.top());
}

TEST(BinaryHeapTest, Can_Move_Heap) {
  // Arrange
  BinaryHeap<int> h {2, -5, 1, 2};

  // Act
  BinaryHeap<int> ch(std::move(h));

  // Assert
  EXPECT_EQ(2, ch.top());
}

TEST(BinaryHeapTest, Can_Assign_Move_Heap) {
  // Arrange
  BinaryHeap<int> h1 {3, 9, 15};
  BinaryHeap<int> h2 {5, 3, 1};

  // Act
  h2 = std::move(h1);

  // Assert
  EXPECT_EQ(15, h2.top());
}

TEST(BinaryHeapTest, Throw_When_Delete_Top_From_Empty_Heap) {
  // Arrange
  BinaryHeap<int> heap;

  // Act & Assert
  ASSERT_NO_THROW(heap.pop());
}

TEST(BinaryHeapTest, Check_Delete_Top) {
  // Arrange
  BinaryHeap<int> heap = {3, 5, 10, 2, 1};

  // Act
  heap.pop();

  // Assert
  EXPECT_EQ(5, heap.top());
}

TEST(BinaryHeapTest, Check_Use_Other_Comparator) {
  // Arrange
  BinaryHeap<int, std::less<int>> heap = {3, 5, 10, 2, 1};

  // Act
  heap.pop();

  // Assert
  EXPECT_EQ(1, heap.top());
}
