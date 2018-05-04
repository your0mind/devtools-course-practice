// Copyright 2018 Krasikova Ekaterina

#include <gtest/gtest.h>

#include "include/Node.h"

TEST(NodeTest,
    There_is_no_throw_when_create_null_node) {
    EXPECT_NO_THROW(node n);
}
TEST(NodeTest, Can_create_null_node) {
    node n;
    EXPECT_EQ(0, n.key);
}
TEST(NodeTest,
    There_is_no_throw_when_create_not_null_node) {
    EXPECT_NO_THROW(node n(10));
}
TEST(NodeTest, Can_create_not_null_node) {
    node n(10);
    EXPECT_EQ(10, n.key);
}
