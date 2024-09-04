// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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
    TreeNode *sortedArrayToBST(vector<int> &nums, int st, int en)
    {
        // Base Case
        if (st > en)
        {
            return NULL;
        }

        int mid = st + ((en - st) / 2);

        TreeNode *curr = new TreeNode(nums[mid]);
        TreeNode *left = sortedArrayToBST(nums, st, mid - 1);
        TreeNode *right = sortedArrayToBST(nums, mid + 1, en);

        curr->left = left;
        curr->right = right;

        return curr;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};