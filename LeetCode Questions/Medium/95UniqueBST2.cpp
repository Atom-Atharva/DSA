// https://leetcode.com/problems/unique-binary-search-trees-ii/description/

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

class Solution
{
    vector<TreeNode *> generateTrees(vector<int> &nodes, int st, int en)
    {
        if (st > en)
        {
            return {NULL};
        }

        if (st == en)
        {
            TreeNode *root = new TreeNode(nodes[st]);
            return {root};
        }

        vector<TreeNode *> trees;
        for (int i = st; i <= en; i++)
        {
            vector<TreeNode *> leftTrees = generateTrees(nodes, st, i - 1);
            vector<TreeNode *> rightTrees = generateTrees(nodes, i + 1, en);

            for (int j = 0; j < leftTrees.size(); j++)
            {
                for (int k = 0; k < rightTrees.size(); k++)
                {
                    TreeNode *root = new TreeNode(nodes[i]);
                    root->left = leftTrees[j];
                    root->right = rightTrees[k];

                    trees.push_back(root);
                }
            }
        }

        return trees;
    }

public:
    vector<TreeNode *> generateTrees(int n)
    {
        vector<int> nodes(n);
        for (int i = 0; i < n; i++)
        {
            nodes[i] = i + 1;
        }

        vector<TreeNode *> trees = generateTrees(nodes, 0, n - 1);

        return trees;
    }
};