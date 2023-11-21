// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2023-11-17

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        // Sort Array--
        sort(nums.begin(), nums.end());

        // Pairs Form--
        int maximum = 0;
        int st = 0, en = nums.size() - 1;
        while (st < en)
        {
            // Set Maximum--
            int sum = nums[st] + nums[en];
            maximum = max(sum, maximum);

            // Update Loop--
            st++, en--;
        }

        return maximum;
    }
};