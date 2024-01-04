// https://leetcode.com/problems/contains-duplicate-ii/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.count(nums[i]) > 0)
            {
                int j = umap[nums[i]];
                if (abs(i - j) <= k)
                {
                    return true;
                }
            }
            umap[nums[i]] = i;
        }

        return false;
    }
};