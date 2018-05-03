// Copyright 2018 Krasikova Ekaterina

#include <gtest/gtest.h>

#include "include/leftist_heap.h"

TEST(LeftistHeapTest,
    There_is_no_throw_when_create_leftist_heap_with_null_root) {
    EXPECT_NO_THROW(leftist_heap h);
}
TEST(LeftistHeapTest,
    There_is_no_throw_when_create_leftist_heap_with_not_null_root) {
    node *root = new node;
    EXPECT_NO_THROW(leftist_heap h(root));
}
TEST(LeftistHeapTest, Create_correct_leftist_heap_with_the_root) {
    // Arrange
    node *root = new node(10);
    // Act
    leftist_heap h(root);
    // Assert
    EXPECT_EQ(h.root->key, 10);
}
TEST(LeftistHeapTest, Create_correct_copy_of_the_leftist_heap_with_null_root) {
    // Arrange
    leftist_heap h1;
    // Act
    leftist_heap h2(h1);
    // Assert
    EXPECT_EQ(h2.root, nullptr);
}
TEST(LeftistHeapTest,
    Create_correct_copy_of_the_leftist_heap_with_not_null_root) {
    // Arrange
    node *root = new node(10);
    leftist_heap h1(root);
    // Act
    leftist_heap h2(h1);
    // Assert
    EXPECT_EQ(h2.root->key, 10);
}

TEST(LeftistHeapTest, There_is_no_throw_when_assign_to_itself) {
    node *root = new node(10);
    leftist_heap h1(root);
    EXPECT_NO_THROW(h1 = h1);
}
TEST(LeftistHeapTest, Can_assign_to_the_leftist_heap_with_null_root) {
    // Arrange
    node *root = new node(10);
    leftist_heap h1(root);
    leftist_heap h2;
    // Act
    h2 = h1;
    // Assert
    EXPECT_EQ(h2.root->key, 10);
}
TEST(LeftistHeapTest, Can_assign_to_the_leftist_heap_with_not_null_root) {
    // Arrange
    node *root = new node(10);
    leftist_heap h1(root);
    node *root2 = new node(5);
    leftist_heap h2(root2);
    // Act
    h2 = h1;
    // Assert
    EXPECT_EQ(h2.root->key, 10);
}
TEST(LeftistHeapTest,
    There_is_no_throw_when_merge_two_leftist_heap_with_null_root) {
    leftist_heap h1;
    leftist_heap *h2 = new leftist_heap;
    EXPECT_NO_THROW(h1.merge(h2));
}
TEST(LeftistHeapTest,
    There_is_no_throw_when_merge_null_root_heap_with_not_null_root_heap) {
    leftist_heap h1;
    node *root2 = new node(5);
    leftist_heap *h2 = new leftist_heap(root2);
    EXPECT_NO_THROW(h1.merge(h2));
}
TEST(LeftistHeapTest,
    There_is_no_throw_when_merge_not_null_root_heap_with_null_root_heap) {
    leftist_heap *h1 = new leftist_heap;
    node *root2 = new node(5);
    leftist_heap h2(root2);
    EXPECT_NO_THROW(h2.merge(h1));
}
TEST(LeftistHeapTest,
    There_is_no_throw_when_merge_two_leftist_heap_with_not_null_root) {
    node *root = new node(10);
    leftist_heap h1(root);
    node *root2 = new node(5);
    leftist_heap *h2 = new leftist_heap(root2);
    EXPECT_NO_THROW(h1.merge(h2));
}
TEST(LeftistHeapTest, Correct_merge_two_leftist_heap_with_not_null_root) {
    // Arrange
    node *root = new node(10);
    leftist_heap h1(root);
    node *root2 = new node(5);
    leftist_heap *h2 = new leftist_heap(root2);
    // Act
    h1.merge(h2);
    // Assert
    EXPECT_EQ(h1.root->key, 5);
}
TEST(LeftistHeapTest, Can_insert_in_the_leftist_heap_with_null_root) {
    // Arrange
    leftist_heap h1;
    // Act
    h1.insert(5);
    // Assert
    EXPECT_EQ(h1.root->key, 5);
}
TEST(LeftistHeapTest, Can_insert_in_the_leftist_heap_with_not_null_root) {
    // Arrange
    leftist_heap h1;
    h1.insert(5);
    // Act
    h1.insert(2);
    // Assert
    EXPECT_EQ(2, h1.root->key);
}
TEST(LeftistHeapTest,
    There_is_a_throw_when_find_minimum_in_the_leftist_heap_with_null_root) {
    leftist_heap h1;
    EXPECT_ANY_THROW(h1.MinKey());
}
TEST(LeftistHeapTest,
    Can_find_minimum_in_the_leftist_heap_with_not_null_root) {
    // Arrange
    leftist_heap h1;
    h1.insert(5);
    h1.insert(2);
    // Act
    int min = h1.MinKey();
    // Assert
    EXPECT_EQ(2, h1.root->key);
}
TEST(LeftistHeapTest,
    There_is_a_throw_when_delete_minimum_in_the_leftist_heap_with_null_root) {
    leftist_heap h1;
    EXPECT_ANY_THROW(h1.DeleteMin());
}
TEST(LeftistHeapTest,
    Can_delete_minimum_in_the_leftist_heap_with_not_null_root) {
    // Arrange
    leftist_heap h1;
    h1.insert(5);
    h1.insert(2);
    // Act
    h1.DeleteMin();
    // Assert
    EXPECT_EQ(5, h1.MinKey());
}
TEST(LeftistHeapTest, Work_right_for_sorting_array) {
    // Arrange
    leftist_heap h1;
    h1.insert(5);
    h1.insert(2);
    h1.insert(3);
    h1.insert(10);
    int exp[] = { 2, 3, 5, 10 };
    int* res = new int[4];
    // Act
    for (int i = 0; i < 4; ++i) {
        res[i] = h1.MinKey();
        h1.DeleteMin();
    }
    // Assert
    for (int i = 0; i < 4; ++i) {
        EXPECT_EQ(exp[i], res[i]);
    }
}
TEST(LeftistHeapTest, Can_assign_to_the_leftist_heap_with_many_nodes) {
    // Arrange
    leftist_heap h1;
    h1.insert(5);
    h1.insert(2);
    h1.insert(3);
    h1.insert(10);
    leftist_heap h2;
    h2.insert(5);
    h2.insert(2);
    h2.insert(7);
    h2.insert(10);
    // Act
    h2 = h1;
    // Assert
    EXPECT_EQ(h2.root->key, h1.root->key);
}

