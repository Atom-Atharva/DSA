// https://leetcode.com/problems/leaf-similar-trees/description/?envType=daily-question&envId=2024-01-09

#include <iostream>
using namespace std;
#include <vector>

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

class Solution
{
    void preOrderLeaf(TreeNode *root, vector<int> &leaf)
    {
        // Base Case--
        if (root == NULL)
        {
            return;
        }
        if (root->left == NULL && root->right == NULL)
        {
            leaf.push_back(root->val);
            return;
        }

        // Recursion Calls--
        preOrderLeaf(root->left, leaf);
        preOrderLeaf(root->right, leaf);

        return;
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leaf1, leaf2;
        preOrderLeaf(root1, leaf1);
        preOrderLeaf(root2, leaf2);

        return (leaf1 == leaf2);
    }
};