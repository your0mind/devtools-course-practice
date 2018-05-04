// Copyright 2018 Gorelova Ksenia

#include <gtest/gtest.h>

#include "include/search_tree.h"

TEST(Gorelova_Ksenia_SearchTree_Test, can_create_tree)
{
    ASSERT_NO_THROW(new SearchTree());
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_delete_empty_tree)
{
    SearchTree *tree = new SearchTree();
    ASSERT_NO_THROW(delete tree);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_delete_not_empty_tree)
{
    SearchTree *tree = new SearchTree();
    double key = 111.111;
    tree->Add(key);
    ASSERT_NO_THROW(delete tree);
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_insert_element_in_empty_tree)
{
    SearchTree *tree = new SearchTree();
    double key = 111.111;
    ASSERT_NO_THROW(tree->Add(key));
    delete tree;
}

TEST(Gorelova_Ksenia_SearchTree_Test, can_search_element)
{
    SearchTree *tree = new SearchTree();
    double key = 111.111;
    tree->Add(key);
    ASSERT_NO_THROW(tree->Search(key));
    delete tree;
}