// https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, bool> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            if (freq[nums[i]])
            {
                return nums[i];
            }
            freq[nums[i]] = 1;
        }

        return -1;
    }
};