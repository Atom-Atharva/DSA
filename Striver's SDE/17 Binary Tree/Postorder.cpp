// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {};
        }

        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        left.insert(left.end(), right.begin(), right.end());
        left.push_back(root->val);

        return left;
    }
};