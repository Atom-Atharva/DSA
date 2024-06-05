// https://leetcode.com/problems/4sum/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    void twoSum(vector<int> &nums, long long target, int st, vector<vector<int>> &ans, int i, int j)
    {
        int en = nums.size() - 1;
        while (st < en)
        {
            if ((long long)nums[st] + nums[en] == target)
            {
                ans.push_back({nums[i], nums[j], nums[st], nums[en]});
                while (st < en && nums[st] == nums[st + 1])
                {
                    st++;
                }
                st++, en--;
            }
            else if ((long long)nums[st] + nums[en] > target)
            {
                en--;
            }
            else
            {
                st++;
            }
        }
    }

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
        {
            return {};
        }

        // Sort
        sort(nums.begin(), nums.end());

        // Fix 2
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                // Two Sum on Remaining
                long long rem = (long long)target - nums[i] - nums[j];
                twoSum(nums, rem, j + 1, ans, i, j);
            }
        }

        // Return Answer
        return ans;
    }
};