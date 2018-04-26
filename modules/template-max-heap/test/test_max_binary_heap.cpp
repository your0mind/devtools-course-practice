/* Copyright 2018 TolyaTalamanov */

#include <gtest/gtest.h>
#include "include/max_binary_heap.hpp"

TEST(MaxBinaryHeapTest, Can_Create_Empty_Heap) {
  ASSERT_NO_THROW(MaxBinaryHeap<int> heap);
}

TEST(MaxBinaryHeapTest, Can_Create_Heap_With_Reserved_Memory) {
  ASSERT_NO_THROW(MaxBinaryHeap<int> heap(100));
}

TEST(MaxBinaryHeapTest, Can_Create_Heap_From_Initializer_List) {
  ASSERT_NO_THROW(MaxBinaryHeap<int> heap{1});
}

TEST(MaxBinaryHeapTest, Check_That_Empty_Heap_Is_Empty) {
  MaxBinaryHeap<int> heap;

  ASSERT_TRUE(heap.empty());
}

TEST(MaxBinaryHeapTest, Check_Heap_Size) {
  MaxBinaryHeap<int> heap;

  for (int i = 0; i < 100; ++i) {
    heap.add(i);
  }

  EXPECT_EQ(100, heap.getHeapSize());
}

TEST(MaxBinaryHeapTest, Right_Add_Element) {
  MaxBinaryHeap<int> heap = {1, 3, 5};

  heap.add(1000);

  EXPECT_EQ(1000, heap.getMax());
}

TEST(MaxBinaryHeapTest, Throw_When_Get_Max_From_Empty_Heap) {
  MaxBinaryHeap<int> heap;

  ASSERT_ANY_THROW(heap.getMax());
}

TEST(MaxBinaryHeapTest, Check_Get_Max) {
  MaxBinaryHeap<int> heap;

  for (int i = 0; i < 4; ++i) {
    heap.add(i);
  }

  EXPECT_EQ(3, heap.getMax());
}

TEST(MaxBinaryHeapTest, Throw_When_Delete_Max_From_Empty_Heap) {
  MaxBinaryHeap<int> heap;

  ASSERT_NO_THROW(heap.deleteMax());
}

TEST(MaxBinaryHeapTest, Check_Delete_Max) {
  MaxBinaryHeap<int> heap = {3, 5, 10, 2, 1};

  heap.deleteMax();

  EXPECT_EQ(5, heap.getMax());
}
