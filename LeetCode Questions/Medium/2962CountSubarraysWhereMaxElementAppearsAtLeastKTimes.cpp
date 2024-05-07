// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/?envType=daily-question&envId=2024-03-29

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxElement = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxElement)
            {
                maxElement = nums[i];
            }
        }

        int maxCount = 0;
        long long count = 0;
        int st = 0, en = 0;
        while (st < nums.size())
        {
            if (nums[st] == maxElement)
            {
                maxCount++;
            }
            while (maxCount >= k && en <= st)
            {
                // Add All Possible Subarrays starting with en
                count = count + (nums.size() - st);
                if (nums[en] == maxElement)
                {
                    maxCount--;
                }
                en++;
            }
            st++;
        }

        return count;
    }
};