// https://leetcode.com/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Sort the array--
        sort(nums.begin(), nums.end());

        // Count majority concecutive numbers.
        int count = 0;
        int marked = nums[0];
        int ans = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == marked)
            {
                count++;
            }
            else
            {
                marked = nums[i];
                count = 1;
            }
            if (count > nums.size() / 2)
            {
                ans = marked;
            }
        }

        return ans;
    }
};