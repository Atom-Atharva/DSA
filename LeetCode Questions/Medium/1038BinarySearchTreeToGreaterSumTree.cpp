// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/?envType=daily-question&envId=2024-06-25

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

#include <iostream>
using namespace std;

class Solution
{
    pair<TreeNode *, int> bstToGst(TreeNode *root, int greater)
    {
        if (root == NULL)
        {
            return {NULL, 0};
        }
        if (root->left == NULL && root->right == NULL)
        {
            return {root, root->val};
        }

        pair<TreeNode *, int> right = bstToGst(root->right, greater);
        root->val = root->val + greater + right.second;
        pair<TreeNode *, int> left = bstToGst(root->left, root->val);

        return {root, right.second + left.second + root->val};
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return root;
        }

        return bstToGst(root, 0).first;
    }
};