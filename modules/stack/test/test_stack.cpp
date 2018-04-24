// Copyright 2018 Gladyshev Alexey

#include <gtest/gtest.h>

#include <string>

#include "include/stack.h"

TEST(Gladyshev_Alexey_StackTest, Always_Correct_Test) {
	// Arrange
	int hello = 1;
	int world = 1;
	int assert = 0;
	
	// Act
	assert = hello + world;
	
	// Assert
	EXPECT_EQ(assert, 2);
}

TEST(Gladyshev_Alexey_StackTest, Can_CreateStack_With_My_Size) {
	// Arrange
	TStack<int> stack(10);
	int size = 0;

	// Act
	size = stack.GetSize();

	// Assert
	EXPECT_EQ(size, 10);
}
