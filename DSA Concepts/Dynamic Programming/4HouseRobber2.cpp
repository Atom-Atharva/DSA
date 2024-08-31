// https://leetcode.com/problems/house-robber-ii/description/

#include <iostream>
using namespace std;
#include <vector>

// Space Optimization
class Solution
{
    int robTab(vector<int> &nums)
    {
        int next1 = 0;
        int next2 = 0;

        for (int pos = nums.size() - 1; pos >= 0; pos--)
        {
            int steal = next2 + nums[pos];
            int ignore = next1;

            int curr = max(steal, ignore);

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }

public:
    int rob(vector<int> &nums)
    {
        // Base Case
        if (nums.size() == 1)
        {
            return max(0, nums[0]);
        }

        // Break NUMS in 2 Arrays such that:
        vector<int> nums1;
        nums1.insert(nums1.begin(), nums.begin(), nums.end() - 1);
        vector<int> nums2;
        nums2.insert(nums2.begin(), nums.begin() + 1, nums.end());

        return max(robTab(nums1), robTab(nums2));
    }
};

// Dynamic Programming
class SolutionTAB
{
    int robTab(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 2, 0);

        for (int pos = nums.size() - 1; pos >= 0; pos--)
        {
            int steal = dp[pos + 2] + nums[pos];
            int ignore = dp[pos + 1];

            dp[pos] = max(steal, ignore);
        }

        return dp[0];
    }

public:
    int rob(vector<int> &nums)
    {
        // Base Case
        if (nums.size() == 1)
        {
            return max(0, nums[0]);
        }

        // Break NUMS in 2 Arrays such that:
        vector<int> nums1;
        nums1.insert(nums1.begin(), nums.begin(), nums.end() - 1);
        vector<int> nums2;
        nums2.insert(nums2.begin(), nums.begin() + 1, nums.end());

        return max(robTab(nums1), robTab(nums2));
    }
};

// Memomization
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

        int steal = rob(nums, pos + 2, dp) + nums[pos];
        int ignore = rob(nums, pos + 1, dp);

        return dp[pos] = max(steal, ignore);
    }

public:
    int rob(vector<int> &nums)
    {
        // Base Case
        if (nums.size() == 1)
        {
            return max(0, nums[0]);
        }

        // Break NUMS in 2 Arrays such that:
        vector<int> nums1;
        nums1.insert(nums1.begin(), nums.begin(), nums.end() - 1);
        vector<int> nums2;
        nums2.insert(nums2.begin(), nums.begin() + 1, nums.end());

        vector<int> dp1(nums1.size(), -1);
        vector<int> dp2(nums2.size(), -1);

        return max(rob(nums1, 0, dp1), rob(nums2, 0, dp2));
    }
};

// Recursion
class SolutionREC
{
    int rob(vector<int> &nums, int pos, bool take)
    {
        // Base Case
        if (pos >= nums.size())
        {
            return 0;
        }

        // FOR END POINTS
        if (pos == 0)
        {
            int take = rob(nums, pos + 2, false) + nums[pos];
            int ignore = rob(nums, pos + 1, true);

            return max(take, ignore);
        }
        if (pos == nums.size() - 1)
        {
            int loot = 0;
            if (take)
            {
                loot = rob(nums, pos + 2, take) + nums[pos];
            }
            loot = max(loot, rob(nums, pos + 1, take));

            return loot;
        }

        // STEAL OR IGNORE
        int steal = rob(nums, pos + 2, take) + nums[pos];
        int ignore = rob(nums, pos + 1, take);

        return max(steal, ignore);
    }

public:
    int rob(vector<int> &nums)
    {
        return rob(nums, 0, false);
    }
};