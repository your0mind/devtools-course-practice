// Copyright 2018 Chernenko Valery

#include <gtest/gtest.h>
#include "include/RBTree.h"

TEST(RBTree, can_create_empty_tree) {
    ASSERT_NO_THROW(RBTree T);
}

TEST(RBTree, creation_empty_tree_not_added_node) {
    RBTree T;

    EXPECT_EQ(RBTree::NIL, T.findNode(5));
}

TEST(RBTree, can_create_tree) {
    ASSERT_NO_THROW(RBTree T(5));
}

TEST(RBTree, creation_tree_add_data) {
    RBTree T(5);

    EXPECT_NE(RBTree::NIL, T.findNode(5));
}

TEST(RBTree, can_create_tree_from_array) {
    int array[5];

    for (int i = 0; i < 5; i++)
        array[i] = i * 2;

    ASSERT_NO_THROW(RBTree T(array, 5));
}

TEST(RBTree, creation_tree_from_array_add_node) {
    int array[5];
    bool check = true;

    for (int i = 0; i < 5; i++)
        array[i] = i * 2;
    RBTree T(array, 5);
    for (int i = 0; i < 5; i++)
        if (RBTree::NIL == T.findNode(i * 2)) check = false;

    EXPECT_TRUE(check);
}

TEST(RBTree, can_delete_nonexistent_node) {
    RBTree T(5);

    ASSERT_NO_THROW(T.deleteNode(8));
}

TEST(RBTree, can_delete_node) {
    RBTree T;

    T.insertNode(5);
    T.deleteNode(5);

    EXPECT_EQ(RBTree::NIL, T.findNode(5));
}

TEST(RBTree, can_add_two_node) {
    RBTree T;

    T.insertNode(5);
    T.insertNode(5);

    EXPECT_NE(RBTree::NIL, T.findNode(5));
}

TEST(RBTree, can_delete_two_node) {
    RBTree T;

    T.insertNode(5);
    T.insertNode(5);
    T.deleteNode(5);

    EXPECT_EQ(RBTree::NIL, T.findNode(5));
}
