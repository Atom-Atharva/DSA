// https://leetcode.com/problems/invert-binary-tree/?envType=study-plan-v2&envId=top-interview-150

// Given the root of a binary tree, invert the tree, and return its root.

#include <iostream>
using namespace std;

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

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        // Base Case--
        if (root == NULL)
        {
            return root;
        }

        // Recursive Calls--
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        root->right = left;
        root->left = right;

        return root;
    }
};