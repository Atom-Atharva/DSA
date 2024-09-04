// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

#include <iostream>
using namespace std;
#include <vector>

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
    vector<int> inOrderTraversal(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {};
        }

        vector<int> left = inOrderTraversal(root->left);
        left.push_back(root->val);
        vector<int> right = inOrderTraversal(root->right);
        left.insert(left.end(), right.begin(), right.end());

        return left;
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> tree = inOrderTraversal(root);

        return tree[k - 1];
    }
};