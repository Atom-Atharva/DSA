// https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2024-06-26

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
#include <vector>

class Solution
{
    vector<int> bstToArray(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        if (root->left == NULL && root->right == NULL)
        {
            return {root->val};
        }

        vector<int> left = bstToArray(root->left);
        vector<int> right = bstToArray(root->right);

        left.push_back(root->val);
        left.insert(left.end(), right.begin(), right.end());

        return left;
    }

    TreeNode *arrayToBST(vector<int> &values, int st, int en)
    {
        if (st > en)
        {
            return NULL;
        }
        if (st == en)
        {
            TreeNode *root = new TreeNode(values[st]);
            return root;
        }

        int mid = st + (en - st) / 2;
        TreeNode *root = new TreeNode(values[mid]);

        TreeNode *left = arrayToBST(values, st, mid - 1);
        TreeNode *right = arrayToBST(values, mid + 1, en);

        root->left = left;
        root->right = right;

        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        // Tree to Sorted Array;
        vector<int> values = bstToArray(root);

        TreeNode *newRoot = arrayToBST(values, 0, values.size() - 1);
        return newRoot;
    }
};