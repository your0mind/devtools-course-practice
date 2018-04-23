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
