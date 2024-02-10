// https://leetcode.com/problems/next-permutation/description/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
    void reverse(vector<int> &nums, int st, int en)
    {
        // Reverse Array
        while (st < en)
        {
            // Swap
            nums[st] = nums[st] + nums[en];
            nums[en] = nums[st] - nums[en];
            nums[st] = nums[st] - nums[en];

            st++, en--;
        }

        return;
    }

public:
    void nextPermutation(vector<int> &nums)
    {
        // Start From Back
        int firstSmaller = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            // Find first smaller number
            if (nums[i] < nums[i + 1])
            {
                firstSmaller = i;
                break;
            }
        }
        if (firstSmaller == nums.size() - 1)
        {
            reverse(nums, 0, nums.size() - 1);
            return;
        }

        // Just Greater Number on right side
        int justGreater = firstSmaller;
        int minDiff = INT_MAX;
        for (int i = firstSmaller + 1; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[firstSmaller];
            if (diff > 0 && diff <= minDiff)
            {
                minDiff = diff;
                justGreater = i;
            }
        }

        // Swap those
        int temp = nums[justGreater];
        nums[justGreater] = nums[firstSmaller];
        nums[firstSmaller] = temp;

        // Reverse all numbers from right of first smaller number
        reverse(nums, firstSmaller + 1, nums.size() - 1);

        return;
    }
};