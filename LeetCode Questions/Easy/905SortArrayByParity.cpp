// https://leetcode.com/problems/sort-array-by-parity/?envType=daily-question&envId=2023-09-28

// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

// Return any array that satisfies this condition.

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int even = 0;
        int odd = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                ans[even++] = nums[i];
            }
            else
            {
                ans[odd--] = nums[i];
            }
        }

        return ans;
    }
};