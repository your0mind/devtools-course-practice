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

TEST(Gladyshev_Alexey_StackTest, Can_Create_Stack_With_My_Size) {
	// Arrange
	TStack<int> stack(47);
	int size = 0;

	// Act
	size = stack.GetSize();

	// Assert
	EXPECT_EQ(size, 47);
}

TEST(Gladyshev_Alexey_StackTest, Can_Create_Copy_Stack) {
	// Arrange
	TStack<int> stack(47);

	// Act
	TStack<int> copyStack(stack);

	// Assert
	EXPECT_EQ(stack.GetSize(), copyStack.GetSize());
}
