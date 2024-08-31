// https://www.geeksforgeeks.org/problems/combination-sum-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Memomization
class Solution
{
    void combinationSum(vector<int> &nums, int target, int pos, vector<vector<int>> &ans, vector<int> &comb)
    {
        // Base Case
        if (target == 0)
        {
            ans.push_back(comb);
            return;
        }

        for (int i = pos; i < nums.size(); i++)
        {
            if (target - nums[i] >= 0)
            {
                comb.push_back(nums[i]);
                combinationSum(nums, target - nums[i], i, ans, comb);
                comb.pop_back();
            }
        }

        return;
    }

public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        // SORT A
        sort(A.begin(), A.end());

        // Helper Function
        vector<vector<int>> ans;
        vector<int> comb;
        combinationSum(A, B, 0, ans, comb);

        return ans;
    }
};

// Recursive Method
class Solution
{
    void combinationSum(vector<int> &nums, int target, int pos, vector<vector<int>> &ans, vector<int> &comb)
    {
        // Base Case
        if (target == 0)
        {
            ans.push_back(comb);
            return;
        }

        for (int i = pos; i < nums.size(); i++)
        {
            if (target - nums[i] >= 0)
            {
                // Remove Duplicates
                if (i > pos && nums[i] == nums[i - 1])
                {
                    continue;
                }
                comb.push_back(nums[i]);
                combinationSum(nums, target - nums[i], i, ans, comb);
                comb.pop_back();
            }
        }

        return;
    }

public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        // SORT A
        sort(A.begin(), A.end());

        // Helper Function
        vector<vector<int>> ans;
        vector<int> comb;
        combinationSum(A, B, 0, ans, comb);

        return ans;
    }
};