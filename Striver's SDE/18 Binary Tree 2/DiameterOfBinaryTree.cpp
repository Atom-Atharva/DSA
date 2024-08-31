// https://leetcode.com/problems/diameter-of-binary-tree/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
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
    int maxDia = 0;

    int height(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        maxDia = max(maxDia, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }

        // Play on Height
        height(root);

        return maxDia;
    }
};