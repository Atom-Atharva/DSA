// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/?envType=daily-question&envId=2024-05-27

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        for (int i = 1; i <= nums.size(); i++)
        {
            int count = 0;
            for (auto itr : nums)
            {
                if (itr >= i)
                {
                    count++;
                }
            }
            if (count == i)
            {
                return count;
            }
        }
        return -1;
    }
};