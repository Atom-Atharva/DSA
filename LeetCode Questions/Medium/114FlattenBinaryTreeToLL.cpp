// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
using namespace std;

class Solution
{
    TreeNode *flatToLL(TreeNode *root)
    {
        // Base Case
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return root;
        }

        TreeNode *leftTree = flatToLL(root->left);
        TreeNode *rightTree = flatToLL(root->right);

        TreeNode *temp = root;
        if (leftTree)
        {
            root->right = leftTree;
            root->left = NULL;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
        }
        temp->right = rightTree;

        return root;
    }

public:
    void flatten(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        root = flatToLL(root);
        return;
    }
};