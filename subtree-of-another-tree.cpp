#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* root, TreeNode* anotherRoot) {
        if(root == nullptr && anotherRoot == nullptr) return true;
        if(root == nullptr || anotherRoot == nullptr) return false;
        return isSameTree(root->left, anotherRoot->left) && isSameTree(root->right, anotherRoot->right);
    }
    bool isSubTree(TreeNode* root, TreeNode* subTree) {
        if(subTree == nullptr) return true;
        if(root == nullptr) return false;
        if(isSameTree(root, subTree)) return true;
        return isSubTree(root->left, subTree) || isSubTree(root->right, subTree);
    }
};