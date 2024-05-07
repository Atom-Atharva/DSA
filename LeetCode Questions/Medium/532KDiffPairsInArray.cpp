// https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Method
// 1. Sort
// 2. Binary Search for +k element

class Solution
{
    bool binarySearch(vector<int> &nums, int pos, int k)
    {
        int l = pos, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            if (nums[mid] == k)
            {
                return true;
            }
            else if (nums[mid] > k)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return false;
    }

public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            if (binarySearch(nums, i + 1, nums[i] + k))
            {
                count++;
            }
        }

        return count;
    }
};