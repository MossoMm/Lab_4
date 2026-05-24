#define BOOST_TEST_MODULE TreeTests
#include <boost/test/included/unit_test.hpp>
#include "/tree.h"

BOOST_AUTO_TEST_CASE(InsertAndSearch) {
    BinaryTree tree;
    tree.insert(10);
    BOOST_CHECK(tree.search(10));
    BOOST_CHECK(!tree.search(5));
    BOOST_CHECK_EQUAL(tree.size(), 1);
}

BOOST_AUTO_TEST_CASE(InsertMultiple) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    BOOST_CHECK(tree.search(10));
    BOOST_CHECK(tree.search(5));
    BOOST_CHECK(tree.search(15));
    BOOST_CHECK_EQUAL(tree.size(), 3);
}

BOOST_AUTO_TEST_CASE(RemoveLeaf) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    BOOST_CHECK(tree.remove(5));
    BOOST_CHECK(!tree.search(5));
    BOOST_CHECK_EQUAL(tree.size(), 2);
}

BOOST_AUTO_TEST_CASE(RemoveRoot) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    BOOST_CHECK(tree.remove(10));
    BOOST_CHECK(!tree.search(10));
    BOOST_CHECK_EQUAL(tree.size(), 2);
}

BOOST_AUTO_TEST_CASE(Clear) {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    
    tree.clear();
    BOOST_CHECK_EQUAL(tree.size(), 0);
    BOOST_CHECK(!tree.search(10));
}
