// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

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

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
    void levelOrder(queue<pair<TreeNode *, int>> &nodes, vector<vector<int>> &levelTraversal)
    {
        if (nodes.empty())
        {
            return;
        }

        TreeNode *root = nodes.front().first;
        int level = nodes.front().second;
        nodes.pop();

        if (root->left)
        {
            nodes.push({root->left, level + 1});
        }
        if (root->right)
        {
            nodes.push({root->right, level + 1});
        }

        if (levelTraversal.size() <= level)
        {
            levelTraversal.push_back({root->val});
        }
        else
        {
            levelTraversal[level].push_back({root->val});
        }

        levelOrder(nodes, levelTraversal);
        return;
    }

    void reverse(vector<vector<int>> &levelTraversal)
    {
        for (int i = 0; i < levelTraversal.size() / 2; i++)
        {
            vector<int> temp = levelTraversal[i];
            levelTraversal[i] = levelTraversal[levelTraversal.size() - 1 - i];
            levelTraversal[levelTraversal.size() - 1 - i] = temp;
        }
        return;
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        vector<vector<int>> levelTraversal;
        queue<pair<TreeNode *, int>> nodes;
        nodes.push({root, 0});

        levelOrder(nodes, levelTraversal);

        reverse(levelTraversal);

        return levelTraversal;
    }
};