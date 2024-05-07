// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;

        unordered_map<int, bool> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap[nums[i]])
            {
                ans.push_back(nums[i]);
            }
            umap[nums[i]] = 1;
        }

        return ans;
    }
};