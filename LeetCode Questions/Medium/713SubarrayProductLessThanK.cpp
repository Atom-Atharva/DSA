// https://leetcode.com/problems/subarray-product-less-than-k/?envType=daily-question&envId=2024-03-27

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int product = 1;
            for (int j = i; j < nums.size(); j++)
            {
                product *= nums[j];
                if (product >= k)
                {
                    break;
                }
                count++;
            }
        }

        return count;
    }
};