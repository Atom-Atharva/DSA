// https://leetcode.com/problems/maximum-good-subarray-sum/description/

#include <iostream>
using namespace std;
#include <vector>
#include <climits>
#include <unordered_map>

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long ans = LONG_LONG_MIN;
        long long total = 0;
        unordered_map<int, long long> memo;
        for (const int &i : nums)
        {
            if (memo.count(i) == 0 || memo[i] > total)
                memo[i] = total;
            total += i;
            if (memo.count(i + k))
            {

                ans = max(ans, total - memo[i + k]);
            }
            if (memo.count(i - k))
            {

                ans = max(ans, total - memo[i - k]);
            }
        }
        return ans == LONG_LONG_MIN ? 0 : ans;
    }
};

// Method 2
// Time Complexity: O(n)
// class Solution
// {
// public:
//     long long maximumSubarraySum(vector<int> &nums, int k)
//     {
//         // Calculated Prefix Sum
//         vector<long long> prefixSum(nums.size() + 1, 0);
//         for (int i = 0; i < nums.size(); i++)
//         {
//             prefixSum[i + 1] = prefixSum[i] + nums[i];
//         }

//         long long sum = LONG_LONG_MIN;
//         unordered_map<int, vector<long long>> umap;
//         // For Each Subarray find Good Subarray sum
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (auto itr : umap[nums[i] + k])
//             {
//                 if (i > itr)
//                 {
//                     sum = max(sum, prefixSum[i + 1] - prefixSum[itr]);
//                 }
//                 else
//                 {
//                     sum = max(sum, prefixSum[itr + 1] - prefixSum[i]);
//                 }
//             }
//             for (auto itr : umap[nums[i] - k])
//             {
//                 if (i > itr)
//                 {
//                     sum = max(sum, prefixSum[i + 1] - prefixSum[itr]);
//                 }
//                 else
//                 {
//                     sum = max(sum, prefixSum[itr + 1] - prefixSum[i]);
//                 }
//             }

//             umap[nums[i]].push_back(i);
//         }

//         return sum == LONG_LONG_MIN ? 0 : sum;
//     }
// };

// TLE: O(n^2)
// class Solution
// {
// public:
//     long long maximumSubarraySum(vector<int> &nums, int k)
//     {
//         // Calculated Prefix Sum
//         vector<long long> prefixSum(nums.size() + 1, 0);
//         for (int i = 0; i < nums.size(); i++)
//         {
//             prefixSum[i + 1] = prefixSum[i] + nums[i];
//         }

//         long long sum = INT_MIN;

//         // For Each Subarray find Good Subarray sum
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 if (abs(nums[i] - nums[j]) == k)
//                 {
//                     sum = max(sum, (prefixSum[j + 1] - prefixSum[i]));
//                 }
//             }
//         }

//         return sum == INT_MIN ? 0 : sum;
//     }
// };