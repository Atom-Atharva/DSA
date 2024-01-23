// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/?envType=daily-question&envId=2024-01-11

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
    pair<int, int> findMaxMin(TreeNode *root)
    {
        // Base Case--
        if (root->left == NULL && root->right == NULL)
        {
            return {root->val, root->val};
        }

        // Recursive Calls--
        if (root->left == NULL)
        {
            pair<int, int> rightTree = findMaxMin(root->right);
            pair<int, int> curr;
            curr.first = max(root->val, rightTree.first);
            curr.second = min(root->val, rightTree.second);

            return curr;
        }
        if (root->right == NULL)
        {
            pair<int, int> leftTree = findMaxMin(root->left);
            pair<int, int> curr;
            curr.first = max(root->val, leftTree.first);
            curr.second = min(root->val, leftTree.second);

            return curr;
        }

        pair<int, int> leftTree = findMaxMin(root->left);
        pair<int, int> rightTree = findMaxMin(root->right);

        pair<int, int> curr;
        curr.first = max(root->val, max(leftTree.first, rightTree.first));
        curr.second = min(root->val, min(leftTree.second, rightTree.second));

        return curr;
    }

    void iterateToNodes(TreeNode *root, int &maxDiff)
    {
        // Base Case--
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return;
        }

        // Find MAX and MIN from LEFT and RIGHT Sub-tree
        pair<int, int> maxMinLeft;
        if (root->left != NULL)
        {
            maxMinLeft = findMaxMin(root->left);
            maxDiff = max(maxDiff, max(abs(root->val - maxMinLeft.first), abs(root->val - maxMinLeft.second)));
        }
        pair<int, int> maxMinRight;
        if (root->right != NULL)
        {
            maxMinRight = findMaxMin(root->right);
            maxDiff = max(maxDiff, max(abs(root->val - maxMinRight.first), abs(root->val - maxMinRight.second)));
        }

        // Recursive Calls--
        iterateToNodes(root->left, maxDiff);
        iterateToNodes(root->right, maxDiff);

        return;
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        int maxDiff = 0;
        iterateToNodes(root, maxDiff);

        return maxDiff;
    }
};