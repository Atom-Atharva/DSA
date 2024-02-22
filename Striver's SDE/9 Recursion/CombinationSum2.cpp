// https://leetcode.com/problems/combination-sum-ii/description/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution
{
    void combinationSum2(vector<int> &candidates, int pos, int target, vector<vector<int>> &ans, vector<int> &curr)
    {
        // Base Case--
        if (target < 0)
        {
            return;
        }
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = pos; i < candidates.size(); i++)
        {
            if (i > pos && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            curr.push_back(candidates[i]);
            combinationSum2(candidates, i + 1, target - candidates[i], ans, curr);
            curr.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr = {};
        sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, 0, target, ans, curr);
        return ans;
    }
};