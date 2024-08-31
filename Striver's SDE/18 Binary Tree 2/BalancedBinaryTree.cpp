// https://leetcode.com/problems/balanced-binary-tree/

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
    pair<bool, int> height(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {true, 0};
        }

        pair<bool, int> left = height(root->left);
        pair<bool, int> right = height(root->right);

        bool curr = abs(left.second - right.second) <= 1;

        return {left.first && right.first && curr, max(left.second, right.second) + 1};
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return height(root).first;
    }
};