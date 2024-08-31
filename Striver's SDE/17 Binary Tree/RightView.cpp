// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode *root)
    {
        // Base Case
        if (root == NULL)
        {
            return {};
        }

        // Get Level Wise Order and Take first Node.
        vector<int> view;
        queue<pair<TreeNode *, int>> levelWise;
        levelWise.push({root, 1});

        int prevLvl = 0;
        while (!levelWise.empty())
        {
            TreeNode *curr = levelWise.front().first;
            int lvl = levelWise.front().second;
            levelWise.pop();

            if (lvl != prevLvl)
            {
                view.push_back(curr->val);
            }
            prevLvl = lvl;
            if (curr->right)
            {
                levelWise.push({curr->right, lvl + 1});
            }
            if (curr->left)
            {
                levelWise.push({curr->left, lvl + 1});
            }
        }

        return view;
    }
};