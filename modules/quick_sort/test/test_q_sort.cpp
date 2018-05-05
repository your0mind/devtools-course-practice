// Copyright 2018 Romanov Alexander

#include <gtest/gtest.h>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "include/q_sort.h"

TEST(QuickSortTest, Cant_Sort_Empty_Array) {
  // Arrange
  std::vector<int> arr;
  // Assert
  EXPECT_ANY_THROW(sort::quickSort(arr, 0, 3));
}

TEST(QuickSortTest, Cant_Sort_Negative_index) {
	// Arrange
	std::vector<int> arr = { 2, 1 };
	// Assert
	EXPECT_ANY_THROW(sort::quickSort(arr, -1, 1););
}

TEST(QuickSortTest, Can_Sort_Smoke) {
	// Arrange
	std::vector<int> arr = {2, 1};
	// Act
	sort::quickSort(arr, 0, 1);
	// Assert
	EXPECT_TRUE(arr[0] < arr[1]);
}
