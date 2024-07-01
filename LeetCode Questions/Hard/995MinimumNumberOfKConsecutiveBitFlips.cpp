// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/?envType=daily-question&envId=2024-06-24

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Optimised Approach --> O(n)
class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        // 1. Itterate to 0
        // 2. Store Index in Queue
        // 3. Find Current State of Elements Fliped
        // 4. Remove Out of Range Elements
        // 5. Repeat Cycle

        queue<int> indices;

        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!indices.empty() && i == indices.front() + k)
            {
                indices.pop();
            }

            if ((nums[i] + indices.size()) % 2 == 0)
            {
                count++;
                indices.push(i);
            }
        }
        if (indices.front() + k == nums.size())
        {
            indices.pop();
        }
        if (!indices.empty())
        {
            return -1;
        }

        return count;
    }
};

// TLE --> O(n^2)
class Solution2
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        // 1. Itterate to 0
        // 2. Flip Elements till k
        // 3. Repeat Cycle

        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                continue;
            }

            int j = i;
            for (; j < nums.size() && j < k + i; j++)
            {
                nums[j] = (1 + nums[j]) % 2;
            }
            if (j < k + i)
            {
                return -1;
            }
            count++;
        }

        return count;
    }
};