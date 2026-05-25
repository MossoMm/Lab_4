#include "binary_tree.h"
#include <iostream>
using namespace std;
TreeNode::TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}

BinaryTree::BinaryTree() : root(nullptr), count(0) {}

BinaryTree::~BinaryTree() {
    clear();
}
void BinaryTree::print() {
    printRec(root);
    cout << endl;
}

void BinaryTree::printRec(TreeNode* node) {
    if (node) {
        printRec(node->left);
        cout << node->data << " ";
        printRec(node->right);
    }
}
void BinaryTree::insert(int value) {
    root = insertRec(root, value);
    count++;
}

TreeNode* BinaryTree::insertRec(TreeNode* node, int value) {
    if (!node) return new TreeNode(value);
    
    if (value < node->data)
        node->left = insertRec(node->left, value);
    else if (value > node->data)
        node->right = insertRec(node->right, value);
    
    return node;
}

bool BinaryTree::search(int value) {
    TreeNode* current = root;
    while (current) {
        if (value == current->data) return true;
        if (value < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}

TreeNode* BinaryTree::findMin(TreeNode* node) {
    while (node && node->left) node = node->left;
    return node;
}

TreeNode* BinaryTree::removeRec(TreeNode* node, int value) {
    if (!node) return nullptr;
    
    if (value < node->data)
        node->left = removeRec(node->left, value);
    else if (value > node->data)
        node->right = removeRec(node->right, value);
    else {
        if (!node->left) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        if (!node->right) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        
        TreeNode* temp = findMin(node->right);
        node->data = temp->data;
        node->right = removeRec(node->right, temp->data);
    }
    return node;
}

bool BinaryTree::remove(int value) {
    if (!search(value)) return false;
    root = removeRec(root, value);
    count--;
    return true;
}

int BinaryTree::size() const {
    return count;
}

void BinaryTree::clearRec(TreeNode* node) {
    if (node) {
        clearRec(node->left);
        clearRec(node->right);
        delete node;
    }
}

void BinaryTree::clear() {
    clearRec(root);
    root = nullptr;
    count = 0;
}
