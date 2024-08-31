// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {};
        }

        vector<int> tree;
        tree.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        tree.insert(tree.end(), left.begin(), left.end());
        vector<int> right = preorderTraversal(root->right);
        tree.insert(tree.end(), right.begin(), right.end());

        return tree;
    }
};