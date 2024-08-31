// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {};
        }

        queue<pair<TreeNode *, int>> queue;
        queue.push({root, 0});

        vector<vector<int>> tree;

        int prev = -1;
        while (!queue.empty())
        {
            TreeNode *curr = queue.front().first;
            int currLevel = queue.front().second;
            queue.pop();

            if (currLevel != prev)
            {
                tree.push_back({curr->val});
                prev = currLevel;
            }
            else
            {
                tree[tree.size() - 1].push_back(curr->val);
            }

            if (curr->left)
            {
                queue.push({curr->left, currLevel + 1});
            }
            if (curr->right)
            {
                queue.push({curr->right, currLevel + 1});
            }
        }

        return tree;
    }
};