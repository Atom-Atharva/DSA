// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    TreeNode *ancestor = NULL;

    bool commonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // Base Case
        if (root == NULL)
        {
            return false;
        }

        bool left = commonAncestor(root->left, p, q);
        bool right = commonAncestor(root->right, p, q);

        if (left && right || (left && (root == p || root == q)) || (right && (root == p || root == q)) && ancestor == NULL)
        {
            ancestor = root;
        }

        if (!left && !right)
        {
            if (root == p || root == q)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        commonAncestor(root, p, q);

        return ancestor;
    }
};