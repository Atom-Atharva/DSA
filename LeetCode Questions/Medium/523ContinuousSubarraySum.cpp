// https://leetcode.com/problems/continuous-subarray-sum/description/?envType=daily-question&envId=2024-06-08

#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        // Remender, Index
        unordered_map<int, int> umap;
        umap[0] = -1;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int rem = sum % k;
            if (umap.count(rem) > 0)
            {
                if ((i - umap[rem]) >= 2)
                {
                    return true;
                }
            }
            else
            {
                umap[rem] = i;
            }
        }

        return false;
    }
};