// https://leetcode.com/problems/validate-binary-search-tree/

#include <iostream>
using namespace std;
#include <climits>

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
    pair<pair<long, long>, bool> checkBST(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {{LONG_MAX, LONG_MIN}, true};
        }

        pair<pair<long, long>, bool> left = checkBST(root->left);
        pair<pair<long, long>, bool> right = checkBST(root->right);

        bool curr = left.second && right.second && (root->val > left.first.second && root->val < right.first.first);
        return {{min((long)root->val, left.first.first), max((long)root->val, right.first.second)}, curr};
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return checkBST(root).second;
    }
};