// https://leetcode.com/problems/binary-tree-inorder-traversal/

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

// Special Type of Traversal
// TC : O(N)
// SC : O(1)
// InOrder : Left, Root, Right
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }

        TreeNode *curr = root;
        vector<int> tree;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                tree.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                // Connect Left's Rightmost node with CURR.
                TreeNode *temp = curr->left;
                while (temp->right != NULL)
                {
                    temp = temp->right;
                }
                temp->right = curr;

                // Delete Curr->left
                temp = curr->left;
                curr->left = NULL;
                curr = temp;
            }
        }

        return tree;
    }
};