// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int l, int r, int &k)
    {
        if (l > r)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[k++]);
        int pos = l;
        for (int i = l; i <= r; i++)
        {
            if (root->val == inorder[i])
            {
                pos = i;
                break;
            }
        }

        TreeNode *leftTree = buildTree(preorder, inorder, l, pos - 1, k);
        TreeNode *rightTree = buildTree(preorder, inorder, pos + 1, r, k);

        root->left = leftTree;
        root->right = rightTree;

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
        {
            return NULL;
        }

        int k = 0;
        return buildTree(preorder, inorder, 0, preorder.size() - 1, k);
    }
};