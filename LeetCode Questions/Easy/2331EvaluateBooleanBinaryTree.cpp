// https://leetcode.com/problems/evaluate-boolean-binary-tree/?envType=daily-question&envId=2024-05-16

//  Definition for a binary tree node.
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
public:
    bool evaluateTree(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return root->val;
        }

        bool leftTree = evaluateTree(root->left);
        bool rightTree = evaluateTree(root->right);

        if (root->val == 2)
        {
            return leftTree || rightTree;
        }
        return leftTree && rightTree;
    }
};