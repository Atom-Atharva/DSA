// https://leetcode.com/problems/single-number-iii/description/?envType=daily-question&envId=2024-05-31

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        // Base Case
        if (nums.size() == 2)
        {
            return nums;
        }

        // Calculate XOR
        int xOr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            xOr ^= nums[i];
        }

        int shift = 0;
        while (((xOr >> shift) & 1) == 0)
        {
            shift++;
        }

        // XOR num with 0 on ith Bit
        int a = 0;

        // XOR num with 1 on ith Bit
        int b = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (((nums[i] >> shift) & 1) == 1)
            {
                b ^= nums[i];
            }
            else
            {
                a ^= nums[i];
            }
        }

        return {a, b};
    }
};