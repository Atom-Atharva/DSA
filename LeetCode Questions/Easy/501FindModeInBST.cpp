// https: // leetcode.com/problems/find-mode-in-binary-search-tree/?envType=daily-question&envId=2023-11-01

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> umap;

    void findMODE(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        umap[root->val]++;

        findMODE(root->left);
        findMODE(root->right);

        return;
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        findMODE(root);

        vector<int> ans;
        int maxFreq = 0;
        for (auto itr : umap)
        {
            maxFreq = max(maxFreq, itr.second);
        }
        for (auto itr : umap)
        {
            if (itr.second == maxFreq)
            {
                ans.push_back(itr.first);
            }
        }

        return ans;
    }
};