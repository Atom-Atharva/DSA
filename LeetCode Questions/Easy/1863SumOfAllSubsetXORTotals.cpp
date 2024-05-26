// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/?envType=daily-question&envId=2024-05-20

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int subsetXORSum(vector<int> &nums, int pos = 0, int xOr = 0)
    {
        if (pos == nums.size())
        {
            return xOr;
        }

        int take = subsetXORSum(nums, pos + 1, xOr ^ nums[pos]);
        int ignore = subsetXORSum(nums, pos + 1, xOr);

        return take + ignore;
    }
};