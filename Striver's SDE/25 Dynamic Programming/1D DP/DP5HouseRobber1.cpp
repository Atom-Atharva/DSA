// https://leetcode.com/problems/house-robber/description/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int next = nums[nums.size() - 1];
        int secondNext = 0;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            // Take or not take
            int maxProfit = next;
            maxProfit = max(maxProfit, secondNext + nums[i]);

            secondNext = next;
            next = maxProfit;
        }

        return next;
    }
};

class SolutionTAB
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, 0);
        dp[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            // Take or not take
            int maxProfit = dp[i + 1];
            maxProfit = max(maxProfit, dp[i + 2] + nums[i]);

            dp[i] = maxProfit;
        }

        return dp[0];
    }
};

class SolutionMEM
{
    int rob(vector<int> &nums, int pos, vector<int> &dp)
    {
        // Base Case
        if (pos >= nums.size())
        {
            return 0;
        }
        if (dp[pos] != -1)
        {
            return dp[pos];
        }

        // Take or not take
        int maxProfit = rob(nums, pos + 1, dp);
        maxProfit = max(maxProfit, rob(nums, pos + 2, dp) + nums[pos]);

        return dp[pos] = maxProfit;
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return rob(nums, 0, dp);
    }
};