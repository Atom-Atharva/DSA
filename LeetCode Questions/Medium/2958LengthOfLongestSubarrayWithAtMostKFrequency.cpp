// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int maxLen = 0;
        unordered_map<int, int> umap;

        int st = 0, en = 0;
        while (st < nums.size())
        {
            umap[nums[st]]++;

            while (umap[nums[st]] > k)
            {
                umap[nums[en]]--;
                en++;
            }

            int len = st - en + 1;
            maxLen = max(maxLen, len);
            st++;
        }

        return maxLen;
    }
};