// https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/?envType=daily-question&envId=2023-12-18

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Time Complexity O(n)
// 1. Itterate Over Nums
//      - Select Smallest and Second Smallest
//      - Select Largest and Second Largest
// 2. Return Maximum Product Difference

// Time Complexity O(nlogn)
class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        // Sort
        sort(nums.begin(), nums.end());

        // Select
        return ((nums[nums.size() - 1] * nums[nums.size() - 2]) - (nums[0] * nums[1]));
    }
};