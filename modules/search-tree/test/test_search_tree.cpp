// Copyright 2018 Gorelova Ksenia

#include <gtest/gtest.h>

#include "include/search_tree.h"

TEST(Gorelova_Ksenia_SearchTree_Test, can_create_tree) {
    ASSERT_NO_THROW(new SearchTree());
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_delete_empty_tree) {
    SearchTree *tree = new SearchTree();
    ASSERT_NO_THROW(delete tree);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_delete_not_empty_tree) {
    SearchTree *tree = new SearchTree();
    Tree * tr = nullptr;
    double key = 111.111;
    tree->AddTree(key, &tr);
    ASSERT_NO_THROW(delete tree);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_insert_element_in_empty_tree) {
    SearchTree *tree = new SearchTree();
    double key = 111.111;
    Tree * tr = nullptr;
    ASSERT_NO_THROW(tree->AddTree(key, &tr));
    delete tree;
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_search_element) {
    SearchTree *tree = new SearchTree();
    double key = 111.111;
    Tree * tr = nullptr;
    tree->AddTree(key, &tr);
    ASSERT_NO_THROW(tree->Search(tr, key));
    delete tree;
}
