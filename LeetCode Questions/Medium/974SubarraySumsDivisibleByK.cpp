// https://leetcode.com/problems/subarray-sums-divisible-by-k/?envType=daily-question&envId=2024-06-09

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        umap[0] = 1;

        int count = 0;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int rem = sum % k;
            // Avoid Storing -ve Remainder
            if (rem < 0)
            {
                rem = rem + k;
            }

            if (umap.count(rem) > 0)
            {
                count += umap[rem];
                umap[rem]++;
            }
            else
            {
                umap[rem] = 1;
            }
        }

        return count;
    }
};