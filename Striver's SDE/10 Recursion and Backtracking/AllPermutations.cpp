// https://leetcode.com/problems/permutations/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void permute(vector<int> &nums, vector<vector<int>> &output, vector<int> &ans)
    {
        // Base Case
        if (nums.size() == 0)
        {
            output.push_back(ans);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[i]);

            vector<int> arr;
            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] == nums[i])
                {
                    continue;
                }
                arr.push_back(nums[j]);
            }
            permute(arr, output, ans);
            ans.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> output;
        vector<int> ans;

        permute(nums, output, ans);
        return output;
    }
};