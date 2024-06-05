// https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // Store Numbers
        unordered_map<int, bool> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]] = 1;
        }

        // Check Starting Point and Check Longest Sequence
        int longestSequence = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (umap.count(nums[i] - 1))
            {
                continue;
            }
            else
            {
                int seq = 1;
                int num = nums[i] + 1;
                while (umap.count(num))
                {
                    num++;
                    seq++;
                }
                longestSequence = max(longestSequence, seq);
            }
        }

        return longestSequence;
    }
};