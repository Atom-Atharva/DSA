// https://leetcode.com/problems/path-sum-ii/

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
#include <vector>

class Solution
{
    void pathSum(TreeNode *root, int targetSum, vector<int> path, vector<vector<int>> &paths)
    {
        if (root == NULL)
        {
            return;
        }

        path.push_back(root->val);
        targetSum -= root->val;

        if (targetSum == 0 && (root->left == NULL && root->right == NULL))
        {
            paths.push_back(path);
            return;
        }

        pathSum(root->left, targetSum, path, paths);
        pathSum(root->right, targetSum, path, paths);

        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<int> path;
        vector<vector<int>> paths;

        pathSum(root, targetSum, path, paths);

        return paths;
    }
};