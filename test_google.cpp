#include <gtest/gtest.h>
#include "tree.h"

TEST(BinaryTreeTest, InsertAndSearch) {
    BinaryTree tree;
    tree.insert(10);
    EXPECT_TRUE(tree.search(10));
    EXPECT_FALSE(tree.search(5));
    EXPECT_EQ(tree.size(), 1);
}

TEST(BinaryTreeTest, InsertMultiple) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    EXPECT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(15));
    EXPECT_EQ(tree.size(), 3);
}

TEST(BinaryTreeTest, RemoveLeaf) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    EXPECT_TRUE(tree.remove(5));
    EXPECT_FALSE(tree.search(5));
    EXPECT_EQ(tree.size(), 2);
}

TEST(BinaryTreeTest, RemoveRoot) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    EXPECT_TRUE(tree.remove(10));
    EXPECT_FALSE(tree.search(10));
    EXPECT_EQ(tree.size(), 2);
}

TEST(BinaryTreeTest, RemoveNonExistent) {
    BinaryTree tree;
    tree.insert(10);
    
    EXPECT_FALSE(tree.remove(20));
    EXPECT_EQ(tree.size(), 1);
}

TEST(BinaryTreeTest, Clear) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    tree.clear();
    EXPECT_EQ(tree.size(), 0);
    EXPECT_FALSE(tree.search(10));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
