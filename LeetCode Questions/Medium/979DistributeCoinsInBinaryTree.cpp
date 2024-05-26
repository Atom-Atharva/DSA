// https://leetcode.com/problems/distribute-coins-in-binary-tree/description/?envType=daily-question&envId=2024-05-18

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
    int distributeCoins(TreeNode *root, int &steps)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }

        int leftTree = distributeCoins(root->left, steps);
        int rightTree = distributeCoins(root->right, steps);

        steps += abs(leftTree) + abs(rightTree);
        return (leftTree + rightTree - (root->val - 1));
    }

public:
    int distributeCoins(TreeNode *root)
    {
        int steps = 0;
        distributeCoins(root, steps);

        return steps;
    }
};