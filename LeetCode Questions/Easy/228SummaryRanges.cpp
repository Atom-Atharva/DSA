// https://leetcode.com/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return {};
        }

        vector<string> range;

        int st = 0, en = 0;
        int prev = nums[st];
        while (en < nums.size())
        {
            if (st == en)
            {
                en++;
                continue;
            }
            if (nums[en] != prev + 1)
            {
                if (st == en - 1)
                {
                    range.push_back(to_string(nums[st]));
                }
                else
                {
                    range.push_back(to_string(nums[st]) + "->" + to_string(nums[en - 1]));
                }
                st = en;
            }
            prev = nums[en];
            en++;
        }

        if (st == en - 1)
        {
            range.push_back(to_string(nums[st]));
        }
        else
        {
            range.push_back(to_string(nums[st]) + "->" + to_string(nums[en - 1]));
        }

        return range;
    }
};