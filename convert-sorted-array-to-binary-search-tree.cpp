#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode() : val(0), right(nullptr), left(nullptr) {}
    TreeNode(int x) : val(x), right(nullptr), left(nullptr) {}
    TreeNode(int x, TreeNode* right, TreeNode* left) : val(x), right(right), left(left) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums){
        return arrayToBST(nums, 0, nums.size());
    }

    TreeNode* arrayToBST(vector<int>& nums, int start, int end){
        if(start >= end) return nullptr;

        int mid = (start + end) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = arrayToBST(nums, start, mid);

        root->right = arrayToBST(nums, mid+1, end);

        return root;
    }
};