#include <gtest/gtest.h>
#include "tree.h"
#include "stack.h"
#include "queue.h"

//Tree

TEST(TreeTest, InsertAndSearch) {
    BinaryTree tree;
    tree.insert(10);
    EXPECT_TRUE(tree.search(10));
    EXPECT_FALSE(tree.search(5));
}

TEST(TreeTest, InsertMultiple) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    EXPECT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(15));
}

TEST(TreeTest, RemoveLeaf) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    EXPECT_TRUE(tree.remove(5));
    EXPECT_FALSE(tree.search(5));
    EXPECT_TRUE(tree.search(10));
    EXPECT_TRUE(tree.search(15));
}

TEST(TreeTest, RemoveRoot) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    EXPECT_TRUE(tree.remove(10));
    EXPECT_FALSE(tree.search(10));
    EXPECT_TRUE(tree.search(5));
    EXPECT_TRUE(tree.search(15));
}

TEST(TreeTest, RemoveNonExistent) {
    BinaryTree tree;
    tree.insert(10);
    
    EXPECT_FALSE(tree.remove(20));
    EXPECT_TRUE(tree.search(10));
}

TEST(TreeTest, ClearTree) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    tree.clear();
    EXPECT_FALSE(tree.search(10));
    EXPECT_FALSE(tree.search(5));
    EXPECT_FALSE(tree.search(15));
}

//Stack

TEST(StackTest, PushAndSearch) {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    EXPECT_TRUE(stack.search(10));
    EXPECT_TRUE(stack.search(20));
    EXPECT_TRUE(stack.search(30));
    EXPECT_FALSE(stack.search(5));
    EXPECT_EQ(stack.size(), 3);
}

TEST(StackTest, Pop) {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    EXPECT_TRUE(stack.pop());
    EXPECT_EQ(stack.size(), 2);
    EXPECT_TRUE(stack.search(10));
    EXPECT_TRUE(stack.search(20));
    EXPECT_FALSE(stack.search(30));
}

TEST(StackTest, PopOrder) {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    stack.pop();
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    EXPECT_TRUE(stack.search(10));
    EXPECT_FALSE(stack.search(20));
    EXPECT_FALSE(stack.search(30));
}

TEST(StackTest, PopEmpty) {
    Stack stack;
    EXPECT_FALSE(stack.pop());
    EXPECT_EQ(stack.size(), 0);
}

TEST(StackTest, ClearStack) {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    stack.clear();
    EXPECT_EQ(stack.size(), 0);
    EXPECT_FALSE(stack.search(10));
    EXPECT_FALSE(stack.search(20));
    EXPECT_FALSE(stack.search(30));
}

TEST(StackTest, IsEmpty) {
    Stack stack;
    EXPECT_TRUE(stack.isEmpty());
    
    stack.push(10);
    EXPECT_FALSE(stack.isEmpty());
    
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}

//Queue

TEST(QueueTest, EnqueueAndSearch) {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    EXPECT_TRUE(queue.search(10));
    EXPECT_TRUE(queue.search(20));
    EXPECT_TRUE(queue.search(30));
    EXPECT_FALSE(queue.search(5));
    EXPECT_EQ(queue.size(), 3);
}

TEST(QueueTest, Dequeue) {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    EXPECT_TRUE(queue.dequeue());
    EXPECT_EQ(queue.size(), 2);
    EXPECT_FALSE(queue.search(10));
    EXPECT_TRUE(queue.search(20));
    EXPECT_TRUE(queue.search(30));
}

TEST(QueueTest, DequeueOrder) {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    queue.dequeue();
    queue.dequeue();
    EXPECT_EQ(queue.size(), 1);
    EXPECT_FALSE(queue.search(10));
    EXPECT_FALSE(queue.search(20));
    EXPECT_TRUE(queue.search(30));
}

TEST(QueueTest, DequeueEmpty) {
    Queue queue;
    EXPECT_FALSE(queue.dequeue());
    EXPECT_EQ(queue.size(), 0);
}

TEST(QueueTest, ClearQueue) {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    queue.clear();
    EXPECT_EQ(queue.size(), 0);
    EXPECT_FALSE(queue.search(10));
    EXPECT_FALSE(queue.search(20));
    EXPECT_FALSE(queue.search(30));
}

TEST(QueueTest, IsEmpty) {
    Queue queue;
    EXPECT_TRUE(queue.isEmpty());
    
    queue.enqueue(10);
    EXPECT_FALSE(queue.isEmpty());
    
    queue.dequeue();
    EXPECT_TRUE(queue.isEmpty());
}

//Main

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
