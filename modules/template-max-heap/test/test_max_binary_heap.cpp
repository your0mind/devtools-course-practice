/* Copyright 2018 TolyaTalamanov */

#include <gtest/gtest.h>
#include "include/max_binary_heap.hpp"

TEST(MaxBinaryHeapTest, Can_Create_Empty_Heap) {
  // AAA
  ASSERT_NO_THROW(MaxBinaryHeap<int> heap);
}

TEST(MaxBinaryHeapTest, Can_Create_Heap_With_Reserved_Memory) {
  // AAA
  ASSERT_NO_THROW(MaxBinaryHeap<int> heap(100));
}

TEST(MaxBinaryHeapTest, Can_Create_Heap_From_Initializer_List) {
  // AAA
  ASSERT_NO_THROW(MaxBinaryHeap<int> heap{1});
}

TEST(MaxBinaryHeapTest, Check_That_Empty_Heap_Is_Empty) {
  // Arrange
  MaxBinaryHeap<int> heap;

  // Act & Assert
  ASSERT_TRUE(heap.empty());
}

TEST(MaxBinaryHeapTest, Check_Heap_Size) {
  // Arrange
  MaxBinaryHeap<int> heap;

  // Act
  for (int i = 0; i < 100; ++i) {
    heap.add(i);
  }

  // Assert
  EXPECT_EQ(100, heap.getHeapSize());
}

TEST(MaxBinaryHeapTest, Right_Add_Element) {
  // Arrange
  MaxBinaryHeap<int> heap = {1, 3, 5};

  // Act
  heap.add(1000);

  // Assert
  EXPECT_EQ(1000, heap.getMax());
}

TEST(MaxBinaryHeapTest, Throw_When_Get_Max_From_Empty_Heap) {
  // Arrange
  MaxBinaryHeap<int> heap;

  // Act & Assert
  ASSERT_ANY_THROW(heap.getMax());
}

TEST(MaxBinaryHeapTest, Check_Get_Max) {
  // Arrange
  MaxBinaryHeap<int> heap;

  // Act
  for (int i = 0; i < 4; ++i) {
    heap.add(i);
  }

  // Assert
  EXPECT_EQ(3, heap.getMax());
}

TEST(MaxBinaryHeapTest, Throw_When_Delete_Max_From_Empty_Heap) {
  // Arrange
  MaxBinaryHeap<int> heap;

  // Act & Assert
  ASSERT_NO_THROW(heap.deleteMax());
}

TEST(MaxBinaryHeapTest, Check_Delete_Max) {
  // Arrange
  MaxBinaryHeap<int> heap = {3, 5, 10, 2, 1};

  // Act
  heap.deleteMax();

  // Assert
  EXPECT_EQ(5, heap.getMax());
}
