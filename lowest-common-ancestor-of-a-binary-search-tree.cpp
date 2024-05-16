#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    TreeNode* temp = root;
    while(temp!=nullptr){
        if((p->value<temp->value)&&(q->value<temp->value)){
            temp = temp->left;
        }else if((p->value>temp->value)&&(q->value>temp->value)){
            temp = temp->right;
        }else{
            return temp;
        }
    }
    return nullptr;
}

int main(){

    return 0;
}