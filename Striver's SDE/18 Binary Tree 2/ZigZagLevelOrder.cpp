// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
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
            int lvl = queue.front().second;
            queue.pop();

            if (prev != lvl)
            {
                if (prev > 0 && prev % 2 == 1)
                {
                    reverse(tree[tree.size() - 1].begin(), tree[tree.size() - 1].end());
                }
                prev = lvl;
                tree.push_back({});
            }
            tree[tree.size() - 1].push_back(curr->val);

            if (curr->left)
            {
                queue.push({curr->left, lvl + 1});
            }
            if (curr->right)
            {
                queue.push({curr->right, lvl + 1});
            }
        }
        if (prev > 0 && prev % 2 == 1)
        {
            reverse(tree[tree.size() - 1].begin(), tree[tree.size() - 1].end());
        }

        return tree;
    }
};