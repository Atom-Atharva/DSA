// https://leetcode.com/problems/count-elements-with-maximum-frequency/?envType=daily-question&envId=2024-03-08

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }

        int maxFreq = 0;
        for (auto itr : umap)
        {
            maxFreq = max(maxFreq, itr.second);
        }

        int count = 0;
        for (auto itr : umap)
        {
            if (itr.second == maxFreq)
            {
                count++;
            }
        }

        return count * maxFreq;
    }
};