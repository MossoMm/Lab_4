#ifndef TREE_H
#define TREE_H

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val);
};
class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int value);
    bool search(int value);
    bool remove(int value);
    int size() const;
    void clear();
    
private:
    TreeNode* root;
    int count;

    TreeNode* insertRec(TreeNode* node, int value);
    TreeNode* removeRec(TreeNode* node, int value);
    TreeNode* findMin(TreeNode* node);
    void clearRec(TreeNode* node);
};
#endif
