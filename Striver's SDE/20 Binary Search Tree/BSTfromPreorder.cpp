// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

#include <iostream>
using namespace std;
#include <vector>

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
    TreeNode *bstFromPreorder(vector<int> &preorder, int st, int en)
    {
        // Base Case
        if (st > en)
        {
            return NULL;
        }

        TreeNode *curr = new TreeNode(preorder[st]);

        int index = en + 1;
        for (int i = st + 1; i <= en; i++)
        {
            if (preorder[i] > preorder[st])
            {
                index = i;
                break;
            }
        }
        TreeNode *left = bstFromPreorder(preorder, st + 1, index - 1);
        TreeNode *right = bstFromPreorder(preorder, index, en);

        curr->left = left;
        curr->right = right;

        return curr;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return bstFromPreorder(preorder, 0, preorder.size() - 1);
    }
};