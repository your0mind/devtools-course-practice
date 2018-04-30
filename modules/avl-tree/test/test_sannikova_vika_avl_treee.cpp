// Copyright 2018 Sannikova Vika

#include <gtest/gtest.h>
#include "include/avl_tree.h"

TEST(Sannikova_Vika_AVLTreeTest, Can_Find_Min_In_AVL_Tree) {
    // Arrange
    AVL avltree;
    int numbers[10] = {0, 2, 4, 5, 6, 91, 90, 82, 42, 15};
    for (int i = 0; i < 10; i++) {
        avltree.insert(avltree.getRoot(), numbers[i]);
    }

    // Act
    int res = avltree.findMin(avltree.getRoot())->key;

    // Assert
    int exp_res = 0;
    EXPECT_EQ(exp_res, res);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_Remove_Min_From_AVL_Tree) {
    // Arrange
    AVL avltree;
    int numbers[10] = {0, 2, 4, 5, 6, 91, 90, 82, 42, 15};
    for (int i = 0; i < 10; i++) {
        avltree.insert(avltree.getRoot(), numbers[i]);
    }

    // Act
    avltree.removeMin(avltree.getRoot());

    // Assert
    int exp_res = 2;
    EXPECT_EQ(exp_res, avltree.findMin(avltree.getRoot())->key);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_Find_Val_In_AVL_Tree) {
    // Arrange
    AVL avltree;
    int numbers[10] = {0, 2, 4, 5, 6, 91, 90, 82, 42, 15};
    for (int i = 0; i < 10; i++) {
        avltree.insert(avltree.getRoot(), numbers[i]);
    }

    // Act
    AVLNode* res = avltree.search(avltree.getRoot(), 91);

    // Assert
    AVLNode* exp_res = NULL;
    EXPECT_NE(exp_res, res);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_NOT_Find_Val_In_AVL_Tree) {
    // Arrange
    AVL avltree;
    int numbers[10] = {0, 2, 4, 5, 6, 91, 90, 82, 42, 15};
    for (int i = 0; i < 10; i++) {
        avltree.insert(avltree.getRoot(), numbers[i]);
    }

    // Act
    AVLNode* res = avltree.search(avltree.getRoot(), 55);

    // Assert
    AVLNode* exp_res = NULL;
    EXPECT_EQ(exp_res, res);
}

TEST(Sannikova_Vika_AVLTreeTest, Can_Remove_From_AVL_Tree) {
    // Arrange
    AVL avltree;
    int numbers[10] = {0, 2, 4, 5, 6, 91, 90, 82, 42, 15};
    for (int i = 0; i < 10; i++) {
        avltree.insert(avltree.getRoot(), numbers[i]);
    }

    // Act
    avltree.remove(avltree.getRoot(), 82);
    AVLNode* res = avltree.search(avltree.getRoot(), 82);

    // Assert
    AVLNode* exp_res = NULL;
    EXPECT_EQ(exp_res, res);
}
