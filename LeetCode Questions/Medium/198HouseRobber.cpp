// https://leetcode.com/problems/house-robber/description/

#include <iostream>
using namespace std;
#include <vector>

// Space Optimization
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // 2 Variables
        int prev1 = 0;
        int prev2 = nums[0];

        for (int i = 2; i <= nums.size(); i++)
        {
            int take = prev1 + nums[i - 1];
            int leave = prev2;
            int curr = max(take, leave);

            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};

// Dynamic Programming
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // Dynamic Array--
        vector<int> dp(nums.size() + 1);

        // Fill Initial Cell--
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= nums.size(); i++)
        {
            int take = dp[i - 2] + nums[i - 1];
            int leave = dp[i - 1];
            dp[i] = max(take, leave);
        }

        return dp[nums.size()];
    }
};

// Memomization Approach
class Solution
{
    int rob(vector<int> &nums, int pos, vector<int> &dp)
    {
        // Base Case--
        if (pos >= nums.size())
        {
            return 0;
        }
        if (dp[pos] != -1)
        {
            return dp[pos];
        }

        // Recursive Calls--
        int take = nums[pos] + rob(nums, pos + 2, dp);
        int leave = rob(nums, pos + 1, dp);

        return dp[pos] = max(take, leave);
    }

public:
    int rob(vector<int> &nums)
    {
        // Dynamic Array--
        vector<int> dp(nums.size(), -1);

        return rob(nums, 0, dp);
    }
};

// Recursive Approach
class Solution
{
public:
    int rob(vector<int> &nums, int pos = 0)
    {
        // Base Case--
        if (pos >= nums.size())
        {
            return 0;
        }

        // Recursive Calls--
        int take = nums[pos] + rob(nums, pos + 2);
        int leave = rob(nums, pos + 1);

        return max(take, leave);
    }
};