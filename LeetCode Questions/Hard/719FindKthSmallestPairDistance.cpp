// https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/?envType=daily-question&envId=2024-08-14

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Brute Force Method:
//  - Heap of max Size K
//  - Remove element when size > k
//  - Return Top Element from MAX Heap.

// Optimized Approach
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        // Get All Possible Differences
        vector<int> arr(nums[nums.size() - 1] + 1, 0);

        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int diff = abs(nums[j] - nums[i]);
                arr[diff]++;
            }
        }

        // Find Kth Position
        int st = 0;
        while (k > 0)
        {
            k -= arr[st];
            st++;
        }

        return st - 1;
    }
};