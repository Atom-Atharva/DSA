// https://leetcode.com/problems/construct-string-from-binary-tree/?envType=daily-question&envId=2023-12-08

#include <iostream>
using namespace std;

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

class Solution
{
public:
    string tree2str(TreeNode *root)
    {
        // Base Case--
        if (root == NULL)
        {
            return "";
        }

        // PreOrder--
        // to_string() --> Handles minus Cases--
        string ans = "" + to_string(root->val);
        string left = tree2str(root->left);
        string right = tree2str(root->right);

        // Conditions--
        if (right == "" && left == "")
        {
            return ans;
        }
        if (right == "")
        {
            ans += '(' + left + ')';
            return ans;
        }

        ans += '(' + left + ')' + '(' + right + ')';
        return ans;
    }
};