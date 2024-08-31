// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

#include <iostream>
using namespace std;
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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode *root)
    {
        // Store Node, Index
        deque<pair<TreeNode *, ll>> queue;
        queue.push_back({root, 0});

        ll maxWidth = 0;
        while (!queue.empty())
        {
            // Update Width
            maxWidth = max(maxWidth, queue.back().second - queue.front().second + 1);

            queue.push_back({NULL, 0});
            while (queue.front().first != NULL)
            {
                // Add Childrens
                TreeNode *curr = queue.front().first;
                ll index = queue.front().second;

                if (curr->left)
                {
                    queue.push_back({curr->left, (2 * index) + 1});
                }
                if (curr->right)
                {
                    queue.push_back({curr->right, (2 * index) + 2});
                }

                queue.pop_front();
            }
            queue.pop_front();
        }

        return maxWidth;
    }
};