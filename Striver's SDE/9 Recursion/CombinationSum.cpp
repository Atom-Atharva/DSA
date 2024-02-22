// https://leetcode.com/problems/combination-sum/

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    void combinationSum(vector<int> &candidates, int pos, int target, vector<vector<int>> &ans, vector<int> &curr)
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
            curr.push_back(candidates[i]);
            combinationSum(candidates, i, target - candidates[i], ans, curr);
            curr.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr = {};
        combinationSum(candidates, 0, target, ans, curr);
        return ans;
    }
};