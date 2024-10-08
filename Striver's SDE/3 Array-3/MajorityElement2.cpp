// https://leetcode.com/problems/majority-element-ii/description/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> majority;
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                count++;
            }
            else
            {
                if (count > nums.size() / 3)
                {
                    majority.push_back(nums[i - 1]);
                }
                count = 1;
            }
        }
        if (count > nums.size() / 3)
        {
            majority.push_back(nums[nums.size() - 1]);
        }

        return majority;
    }
};