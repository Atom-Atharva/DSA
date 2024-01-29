// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/?envType=daily-question&envId=2024-01-24

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

// Method 2 : Counting Digits
class Solution
{
    bool isPseudoPalindromic(vector<int> &digits)
    {
        int odd = 0;
        for (int i = 0; i < 9; i++)
        {
            if (digits[i] % 2 != 0)
            {
                odd++;
            }
        }
        return (odd <= 1);
    }

    int pseudoPalindromicPaths(TreeNode *root, vector<int> &digits)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }
        digits[root->val - 1]++;
        if (root->left == NULL && root->right == NULL)
        {
            if (isPseudoPalindromic(digits))
            {
                digits[root->val - 1]--;
                return 1;
            }

            digits[root->val - 1]--;
            return 0;
        }

        // Recursive Calls
        int leftTree = pseudoPalindromicPaths(root->left, digits);
        int rightTree = pseudoPalindromicPaths(root->right, digits);

        digits[root->val - 1]--;
        return leftTree + rightTree;
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        // Backtrack to Leaf Node
        // Count digit
        // Check for ODDS--

        vector<int> digits(9, 0);
        return pseudoPalindromicPaths(root, digits);
    }
};

// Method 1 : Tracing Path
class Solution
{
    bool isPseudoPalindromic(vector<int> &path)
    {
        vector<int> freq(9, 0);
        for (int i = 0; i < path.size(); i++)
        {
            freq[path[i] - 1]++;
        }

        int odd = 0;
        for (int i = 0; i < 9; i++)
        {
            if (freq[i] % 2 != 0)
            {
                odd++;
            }
        }
        return (odd <= 1);
    }

    int pseudoPalindromicPaths(TreeNode *root, vector<int> &path)
    {
        // Base Case
        if (root == NULL)
        {
            return 0;
        }
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (isPseudoPalindromic(path))
            {
                path.pop_back();
                return 1;
            }

            path.pop_back();
            return 0;
        }

        // Recursive Calls
        int leftTree = pseudoPalindromicPaths(root->left, path);
        int rightTree = pseudoPalindromicPaths(root->right, path);

        path.pop_back();
        return leftTree + rightTree;
    }

public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        // Backtrack to Leaf Node
        // Trace Path
        // Check for Pseudo-Palindromic Path

        vector<int> path;
        return pseudoPalindromicPaths(root, path);
    }
};