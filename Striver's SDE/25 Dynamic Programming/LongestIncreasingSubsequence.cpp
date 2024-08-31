// https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

// Dynamic Programming
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // DP Table
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));

        // Iterate on DP
        for (int pos = nums.size() - 1; pos >= 0; pos--)
        {
            for (int prev = pos - 1; prev >= -1; prev--)
            {
                // Can't Make a Choice
                if (prev != -1 && nums[pos] <= nums[prev])
                {
                    // IGNORE
                    dp[pos][prev + 1] = dp[pos + 1][prev + 1];
                    continue;
                }

                int take = dp[pos + 1][pos + 1] + 1;
                int ignore = dp[pos + 1][prev + 1];

                dp[pos][prev + 1] = max(take, ignore);
            }
        }

        return dp[0][0];
    }
};

// Memomization
class SolutionMEM
{
    int lengthOfLIS(vector<int> &nums, int pos, int prev, vector<vector<int>> &dp)
    {
        // Base Case
        if (pos == nums.size())
        {
            return 0;
        }
        if (dp[pos][prev + 1] != -1)
        {
            return dp[pos][prev + 1];
        }

        // Can't Make a Choice
        if (prev != -1 && nums[pos] <= nums[prev])
        {
            // IGNORE
            return dp[pos][prev + 1] = lengthOfLIS(nums, pos + 1, prev, dp);
        }

        int take = lengthOfLIS(nums, pos + 1, pos, dp) + 1;
        int ignore = lengthOfLIS(nums, pos + 1, prev, dp);

        return dp[pos][prev + 1] = max(take, ignore);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return lengthOfLIS(nums, 0, -1, dp);
    }
};

// Recursion
class SolutionREC
{
    // Take OR Ignore
    int lengthOfLIS(vector<int> &nums, int pos, int prev)
    {
        // Base Case
        if (pos == nums.size())
        {
            return 0;
        }

        // Can't Make a Choice
        if (nums[pos] <= prev)
        {
            // IGNORE
            return lengthOfLIS(nums, pos + 1, prev);
        }

        int take = lengthOfLIS(nums, pos + 1, nums[pos]) + 1;
        int ignore = lengthOfLIS(nums, pos + 1, prev);

        return max(take, ignore);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        return lengthOfLIS(nums, 0, INT_MIN);
    }
};