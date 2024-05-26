// https://leetcode.com/problems/validate-binary-search-tree/

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
#include <climits>

class Solution
{
    pair<bool, pair<long, long>> isValidBSTHelper(TreeNode *root)
    {
        if (root == NULL)
        {
            return {true, {LONG_MAX, LONG_MIN}};
        }
        if (root->left == NULL && root->right == NULL)
        {
            return {true, {root->val, root->val}};
        }

        pair<bool, pair<long, long>> leftTree = isValidBSTHelper(root->left);
        pair<bool, pair<long, long>> rightTree = isValidBSTHelper(root->right);

        if (rightTree.first && leftTree.first && root->val < rightTree.second.first && root->val > leftTree.second.second)
        {
            return {true, {min(leftTree.second.first, (long)root->val), max(rightTree.second.second, (long)root->val)}};
        }
        return {false, {}};
    }

public:
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return true;
        }

        pair<bool, pair<long, long>> isValid = isValidBSTHelper(root);

        return isValid.first;
    }
};