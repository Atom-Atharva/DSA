// https://leetcode.com/problems/max-consecutive-ones/description/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxCount = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        maxCount = max(maxCount, count);

        return maxCount;
    }
};