// https://www.naukri.com/code360/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos

#include <iostream>
using namespace std;

// Following is the TreeNode class structure
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// InOrder Traversal
int floorInBST(TreeNode<int> *root, int X)
{
    // Base Case
    if (root == NULL)
    {
        return -1;
    }

    int left = floorInBST(root->left, X);
    int num = -1;
    if (root->val <= X)
    {
        num = root->val;
    }
    int right = floorInBST(root->right, X);

    return max(num, max(left, right));
}