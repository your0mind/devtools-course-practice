// Copyright 2018 Gorelova Ksenia

#include <gtest/gtest.h>

#include "include/search_tree.h"

TEST(Gorelova_Ksenia_SearchTree_Test, can_create_tree) {
    ASSERT_NO_THROW(new SearchTree());
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_delete_empty_tree) {
    SearchTree * tree = new SearchTree();
    ASSERT_NO_THROW(delete tree);
}

//TEST(Gorelova_Ksenia_SearchTree_Test, can_insert_element_in_empty_tree) {
//    SearchTree * tree = new SearchTree();
//    double key = 11.0;
//    Tree * tr = nullptr;
//    ASSERT_NO_THROW(tree->AddTree(key, &tr));
//    delete tree;
//}

TEST(Gorelova_Ksenia_SearchTree_Test, can_search_element) {
    SearchTree * tree = new SearchTree();
    double key = 11.0;
    Tree * tr = nullptr;
    tree->AddTree(key, &tr);
    ASSERT_NO_THROW(tree->Search(tr, key));
    delete tree;
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_destroy_empty_tree) {
    SearchTree * tree = new SearchTree();
    Tree * tr = nullptr;
    ASSERT_NO_THROW(tree->DestroyBTree(tr));
    delete tree;
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_not_equal) {
    Tree tr1, tr2;
    SearchTree * tree = new SearchTree();
    tr1.value = 5;
    tr2.value = 10;
    tree->AddTree(tr1.value, tree->pRoot);
    tree->AddTree(tr2.value, tree->pRoot);
    ASSERT_TRUE(tr1.value != tr2.value);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_minimal_value) {
    Tree tr1, tr2;
    SearchTree * tree = new SearchTree();
    tr1.value = 5;
    tr2.value = 10;
    tree->AddTree(tr1.value, tree->pRoot);
    tree->AddTree(tr2.value, tree->pRoot);
    ASSERT_TRUE(tr1.value < tr2.value);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_left) {
    SearchTree * tree = new SearchTree();
    Tree tr;
    tr.value = 7;
    int key = 3;
    EXPECT_LE(tree->Search(tree->pRoot, key),
              tree->Search(tree->pRoot, tr.value));
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_right) {
    SearchTree * tree = new SearchTree();
    Tree tr;
    tr.value = 7;
    int key = 10;
    EXPECT_GE(tree->Search(tree->pRoot, key),
              tree->Search(tree->pRoot, tr.value));
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_zero) {
    SearchTree * tree = new SearchTree();
    Tree tr;
    tr.value = 0;
    ASSERT_EQ(0, tr.value);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_destroy) {
    SearchTree * tree = new SearchTree();
    Tree * tr = tree->pRoot;
    ASSERT_NO_THROW(tree->DestroyBTree(tr));
    delete tree;
}
