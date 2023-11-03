// https://leetcode.com/problems/find-pivot-index/description/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        vector<int> lSum;
        vector<int> rSum(nums.size());

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            lSum.push_back(sum);
            sum += nums[i];
        }

        sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            rSum[i] = sum;
            sum += nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (lSum[i] == rSum[i])
            {
                return i;
            }
        }

        return -1;
    }
};