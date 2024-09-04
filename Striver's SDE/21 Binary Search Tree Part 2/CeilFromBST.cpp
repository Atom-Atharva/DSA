// https://www.naukri.com/code360/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos

#include <iostream>
using namespace std;
#include <climits>

// Following is the TreeNode class structure:

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

int calCeil(BinaryTreeNode<int> *node, int x)
{
    // Base Case
    if (node == NULL)
    {
        return INT_MAX;
    }

    int right = calCeil(node->right, x);
    int num = INT_MAX;
    if (node->data >= x)
    {
        num = node->data;
    }
    int left = calCeil(node->left, x);

    return min(num, min(right, left));
}

int findCeil(BinaryTreeNode<int> *node, int x)
{
    int num = calCeil(node, x);
    return (num == INT_MAX) ? -1 : num;
}