// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/?envType=daily-question&envId=2024-06-23

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        int longestSize = 0;

        priority_queue<int> maxQueue;
        maxQueue.push(nums[0]);

        priority_queue<int, vector<int>, greater<int>()> minQueue;
        minQueue.push(nums[0]);

        unordered_map<int, int> umap;
        umap[nums[0]]++;

        int st = 0, en = 0;
        int size = 0;
        while (st <= en && en < nums.size())
        {
            while (!maxQueue.empty() && umap[maxQueue.top()] == 0)
            {
                maxQueue.pop();
            }
            while (!minQueue.empty() && umap[minQueue.top()] == 0)
            {
                minQueue.pop();
            }

            if (maxQueue.top() - minQueue.top() <= limit)
            {
                size++;
                longestSize = max(size, longestSize);
                en++;

                if (en < nums.size())
                {
                    maxQueue.push(nums[en]);
                    minQueue.push(nums[en]);

                    umap[nums[en]]++;
                }
            }
            else
            {
                size--;
                umap[nums[st]]--;
                st++;
            }
        }

        return longestSize;
    }
};