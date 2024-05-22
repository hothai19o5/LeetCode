#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int diameterOfTree = 0;

    int diameterOfBinaryTree(TreeNode *root)
    {
        findDiameter(root);
        
        return diameterOfTree;
    }

    int findDiameter(TreeNode *node)
    {
        if (node == nullptr) return 0; 

        int diameterLeft = findDiameter(node->left);
        int diameterRight = findDiameter(node->right);

        diameterOfTree = max(diameterOfTree, diameterLeft + diameterRight);

        return max(diameterLeft, diameterRight) + 1;
    }
};