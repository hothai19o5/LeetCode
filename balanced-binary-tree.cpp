#include <iostream>

using namespace std;

struct TreeNode
{
    int value;
    TreeNode *rightNode;
    TreeNode *leftNode;
    TreeNode() : value(0), leftNode(nullptr), rightNode(nullptr) {}
    TreeNode(int x) : value(x), leftNode(nullptr), rightNode(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : value(x), leftNode(left), rightNode(right) {}
};
// Đặt tên hàm không đúng ý nghĩa, hàm này có mục đích kiểm tra xem cây có bị lệch không, đệ quy từ cây con ra
int getHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int rightHeight = getHeight(root->rightNode);
    // Nếu cây con bên phải bị lệch thì trả về -1
    if (rightHeight == -1)
        return -1;
    // Nếu cây con bên trái bị lệch thì trả về -1
    int leftHeight = getHeight(root->leftNode);
    if (leftHeight == -1)
        return -1;
    // Nếu 2 bên lệch nhau > 1 thì trả về -1
    if (abs(rightHeight - leftHeight) > 1)  
        return -1;
    // Nếu cây không bị lệch thì trả về số dương
    return max(rightHeight, leftHeight) + 1;
}

bool isBalance(TreeNode *root)
{
    return getHeight(root) != -1;
}

int main()
{
    // Test
}