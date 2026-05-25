#define BOOST_TEST_MODULE DataStructuresTests
#include <boost/test/included/unit_test.hpp>
#include "../include/tree.h"
#include "../include/stack.h"
#include "../include/queue.h"

//Tree

BOOST_AUTO_TEST_SUITE(TreeTests)

BOOST_AUTO_TEST_CASE(InsertAndSearch) {
    BinaryTree tree;
    tree.insert(10);
    BOOST_CHECK(tree.search(10));
    BOOST_CHECK(!tree.search(5));
}

BOOST_AUTO_TEST_CASE(InsertMultiple) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    BOOST_CHECK(tree.search(10));
    BOOST_CHECK(tree.search(5));
    BOOST_CHECK(tree.search(15));
}

BOOST_AUTO_TEST_CASE(RemoveLeaf) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    BOOST_CHECK(tree.remove(5));
    BOOST_CHECK(!tree.search(5));
    BOOST_CHECK(tree.search(10));
    BOOST_CHECK(tree.search(15));
}

BOOST_AUTO_TEST_CASE(RemoveRoot) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    BOOST_CHECK(tree.remove(10));
    BOOST_CHECK(!tree.search(10));
    BOOST_CHECK(tree.search(5));
    BOOST_CHECK(tree.search(15));
}

BOOST_AUTO_TEST_CASE(RemoveNonExistent) {
    BinaryTree tree;
    tree.insert(10);
    
    BOOST_CHECK(!tree.remove(20));
    BOOST_CHECK(tree.search(10));
}

BOOST_AUTO_TEST_CASE(ClearTree) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    tree.clear();
    BOOST_CHECK(!tree.search(10));
    BOOST_CHECK(!tree.search(5));
    BOOST_CHECK(!tree.search(15));
}

BOOST_AUTO_TEST_SUITE_END()

//Stack

BOOST_AUTO_TEST_SUITE(StackTests)

BOOST_AUTO_TEST_CASE(PushAndSearch) {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    BOOST_CHECK(stack.search(10));
    BOOST_CHECK(stack.search(20));
    BOOST_CHECK(stack.search(30));
    BOOST_CHECK(!stack.search(5));
    BOOST_CHECK_EQUAL(stack.size(), 3);
}

BOOST_AUTO_TEST_CASE(Pop) {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    BOOST_CHECK(stack.pop());
    BOOST_CHECK_EQUAL(stack.size(), 2);
    BOOST_CHECK(stack.search(10));
    BOOST_CHECK(stack.search(20));
    BOOST_CHECK(!stack.search(30));
}

BOOST_AUTO_TEST_CASE(PopOrder) {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    stack.pop();
    stack.pop();
    BOOST_CHECK_EQUAL(stack.size(), 1);
    BOOST_CHECK(stack.search(10));
    BOOST_CHECK(!stack.search(20));
    BOOST_CHECK(!stack.search(30));
}

BOOST_AUTO_TEST_CASE(PopEmpty) {
    Stack stack;
    BOOST_CHECK(!stack.pop());
    BOOST_CHECK_EQUAL(stack.size(), 0);
}

BOOST_AUTO_TEST_CASE(ClearStack) {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    stack.clear();
    BOOST_CHECK_EQUAL(stack.size(), 0);
    BOOST_CHECK(!stack.search(10));
    BOOST_CHECK(!stack.search(20));
    BOOST_CHECK(!stack.search(30));
}

BOOST_AUTO_TEST_CASE(IsEmpty) {
    Stack stack;
    BOOST_CHECK(stack.isEmpty());
    
    stack.push(10);
    BOOST_CHECK(!stack.isEmpty());
    
    stack.pop();
    BOOST_CHECK(stack.isEmpty());
}

BOOST_AUTO_TEST_SUITE_END()

//Queue

BOOST_AUTO_TEST_SUITE(QueueTests)

BOOST_AUTO_TEST_CASE(EnqueueAndSearch) {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    BOOST_CHECK(queue.search(10));
    BOOST_CHECK(queue.search(20));
    BOOST_CHECK(queue.search(30));
    BOOST_CHECK(!queue.search(5));
    BOOST_CHECK_EQUAL(queue.size(), 3);
}

BOOST_AUTO_TEST_CASE(Dequeue) {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    BOOST_CHECK(queue.dequeue());
    BOOST_CHECK_EQUAL(queue.size(), 2);
    BOOST_CHECK(!queue.search(10));
    BOOST_CHECK(queue.search(20));
    BOOST_CHECK(queue.search(30));
}

BOOST_AUTO_TEST_CASE(DequeueOrder) {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    queue.dequeue();
    queue.dequeue();
    BOOST_CHECK_EQUAL(queue.size(), 1);
    BOOST_CHECK(!queue.search(10));
    BOOST_CHECK(!queue.search(20));
    BOOST_CHECK(queue.search(30));
}

BOOST_AUTO_TEST_CASE(DequeueEmpty) {
    Queue queue;
    BOOST_CHECK(!queue.dequeue());
    BOOST_CHECK_EQUAL(queue.size(), 0);
}

BOOST_AUTO_TEST_CASE(ClearQueue) {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    queue.clear();
    BOOST_CHECK_EQUAL(queue.size(), 0);
    BOOST_CHECK(!queue.search(10));
    BOOST_CHECK(!queue.search(20));
    BOOST_CHECK(!queue.search(30));
}

BOOST_AUTO_TEST_CASE(IsEmpty) {
    Queue queue;
    BOOST_CHECK(queue.isEmpty());
    
    queue.enqueue(10);
    BOOST_CHECK(!queue.isEmpty());
    
    queue.dequeue();
    BOOST_CHECK(queue.isEmpty());
}

BOOST_AUTO_TEST_SUITE_END()
