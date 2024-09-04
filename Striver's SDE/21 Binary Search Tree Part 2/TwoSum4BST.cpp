// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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

// Method:
// - Do Any Traversal
// - Find Second Pair By Searching in BST
class Solution
{
    bool searchK(TreeNode *root, int k, TreeNode *curr)
    {
        // Base Case
        if (root == NULL)
        {
            return false;
        }
        if (root->val == k && root != curr)
        {
            return true;
        }
        else if (root->val > k)
        {
            return searchK(root->left, k, curr);
        }
        else
        {
            return searchK(root->right, k, curr);
        }
    }

    bool findTarget(TreeNode *root, int k, TreeNode *curr)
    {
        // Base Case
        if (curr == NULL)
        {
            return false;
        }

        bool left = findTarget(root, k, curr->left);
        bool node = searchK(root, k - curr->val, curr);
        if (node)
        {
            return true;
        }
        bool right = findTarget(root, k, curr->right);

        return left || right;
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        return findTarget(root, k, root);
    }
};