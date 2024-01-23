// https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> ans(2);

        vector<int> s(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            if (s[nums[i] - 1] > 0)
            {
                ans[0] = nums[i];
            }
            s[nums[i] - 1] = 1;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 0)
            {
                ans[1] = i + 1;
                break;
            }
        }

        return ans;
    }
};