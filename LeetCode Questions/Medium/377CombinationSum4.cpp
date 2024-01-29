// https://leetcode.com/problems/combination-sum-iv/description/

#include <iostream>
using namespace std;
#include <vector>

// Dynamic Programming--
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target + 1, 1);

        for (int i = 1; i <= target; i++)
        {
            int ways = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0)
                {
                    ways += dp[i - nums[j]];
                }
            }
            dp[i] = ways;
        }

        return dp[target];
    }
};

// Recursive Approach + Memomization--
class Solution
{
    int combinationSum4(vector<int> &nums, int target, vector<int> &dp)
    {
        // Base Case
        if (target < 0)
        {
            return 0;
        }
        if (target == 0)
        {
            return 1;
        }
        if (dp[target - 1] != -1)
        {
            return dp[target - 1];
        }

        // Recursive Calls
        int ways = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int way = combinationSum4(nums, target - nums[i], dp);

            ways += (way > 0) ? way : 0;
        }

        return dp[target - 1] = ways;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target, -1);

        return combinationSum4(nums, target, dp);
    }
};