// https://leetcode.com/problems/subsets-ii/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    void subsetsWithDup(vector<int> &nums, vector<vector<int>> &ans, int pos, int count)
    {
        // Base Case--
        if (pos == nums.size())
        {
            return;
        }

        // If Same elements repeats twice
        if (pos > 0 && nums[pos] == nums[pos - 1])
        {
            int i = count;
            int n = ans.size() - 1;
            while (i--)
            {
                vector<int> curr = ans[n--];
                curr.push_back(nums[pos]);
                ans.push_back(curr);
            }
        }
        else
        {
            int n = ans.size();
            for (int i = 0; i < n; i++)
            {
                vector<int> curr = ans[i];
                curr.push_back(nums[pos]);
                ans.push_back(curr);
            }
            count = n;
        }

        subsetsWithDup(nums, ans, pos + 1, count);
        return;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans = {{}};
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, ans, 0, 1);

        return ans;
    }
};