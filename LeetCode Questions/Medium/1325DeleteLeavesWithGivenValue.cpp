// https://leetcode.com/problems/delete-leaves-with-a-given-value/?envType=daily-question&envId=2024-05-17

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
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        // Base Case
        if (root == NULL)
        {
            return NULL;
        }

        TreeNode *leftTree = removeLeafNodes(root->left, target);
        TreeNode *rightTree = removeLeafNodes(root->right, target);

        root->left = leftTree;
        root->right = rightTree;

        if (root->left == NULL && root->right == NULL && root->val == target)
        {
            return NULL;
        }

        return root;
    }
};