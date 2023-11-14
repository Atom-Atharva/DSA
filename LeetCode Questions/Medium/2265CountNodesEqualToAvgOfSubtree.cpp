// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/?envType=daily-question&envId=2023-11-02

#include <iostream>
using namespace std;

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
    int findSum(TreeNode *root, int &count)
    {
        // Base Case--
        if (root == NULL)
        {
            return 0;
        }

        // Recursive Calls--
        int leftSum = findSum(root->left, count);
        int rightSum = findSum(root->right, count);

        count++;
        return leftSum + rightSum + root->val;
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        // Base Case--
        if (root == NULL)
        {
            return 0;
        }

        // Recursive Calls--
        int countLeft = averageOfSubtree(root->left);
        int countRight = averageOfSubtree(root->right);

        // Left Avg and Right Avg--
        int leftCount = 0;
        int rightCount = 0;
        int leftTree = findSum(root->left, leftCount);
        int rightTree = findSum(root->right, rightCount);

        // Check Condition--
        if (((leftTree + rightTree + root->val) / (leftCount + rightCount + 1)) == root->val)
        {
            return countLeft + countRight + 1;
        }

        return countLeft + countRight;
    }
};      