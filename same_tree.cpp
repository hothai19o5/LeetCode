#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p == nullptr && q == nullptr) return true;
    if(q == nullptr || q == nullptr) return false;
    return (p->val == q->val) && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
}