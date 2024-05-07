// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/?envType=daily-question&envId=2024-03-31

#include <iostream>
using namespace std;
#include <vector>

//*****************************VERY VERY GOOD QUEST******************************//

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int invalidI = -1, minI = -1, maxI = -1, n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
                invalidI = i;
            if (nums[i] == minK)
                minI = i;
            if (nums[i] == maxK)
                maxI = i;

            ans += max(0, min(minI, maxI) - invalidI);
        }

        return ans;
    }
};