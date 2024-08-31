// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/?envType=daily-question&envId=2024-08-04

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        // Get All SubArray
        vector<int> subarray;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                subarray.push_back(sum);
            }
        }

        // Sort
        sort(subarray.begin(), subarray.end());

        // Find Range Sum
        int ans = 0;
        for (int i = left - 1; i < right; i++)
        {
            ans = (ans + subarray[i]) % MOD;
        }

        return ans;
    }
};