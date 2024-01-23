// https://leetcode.com/problems/target-sum/description/

#include <iostream>
using namespace std;
#include <vector>

// Memomization--
class Solution
{
    // TODO: Memomization and DP
    int findTargetSumWays(vector<int> &nums, int target, int pos, vector<vector<int>> &dp)
    {
        // Base Case--
        if (pos == nums.size() && target == 0)
        {
            return 1;
        }
        if (pos == nums.size())
        {
            return 0;
        }
        if (dp[pos][target] != -1)
        {
            return dp[pos][target];
        }

        // Recursive Calls--
        int plus = findTargetSumWays(nums, target + nums[pos], pos + 1, dp);
        int minus = findTargetSumWays(nums, target - nums[pos], pos + 1, dp);

        return dp[pos][target] = plus + minus;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int targetSize = target + sum;
        if (targetSize < 0 || sum < target)
        {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return findTargetSumWays(nums, target, 0, dp);
    }
};

// Recursive Approach--
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target, int pos = 0)
    {
        // Base Case--
        if (pos == nums.size() && target == 0)
        {
            return 1;
        }
        if (pos == nums.size())
        {
            return 0;
        }

        // Recursive Calls--
        int plus = findTargetSumWays(nums, target + nums[pos], pos + 1);
        int minus = findTargetSumWays(nums, target - nums[pos], pos + 1);

        return plus + minus;
    }
};