// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/?envType=daily-question&envId=2024-08-02

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        // Calculate Maximum Size of Window
        int maxWindow = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxWindow += (nums[i] == 1);
        }

        if (maxWindow == 0)
        {
            return 0;
        }

        // Handle Circular Cases
        nums.insert(nums.end(), nums.begin(), nums.end());

        // Sliding Window
        int st = 0, en = 0;
        int ones = (nums[en] == 1);

        int minSwaps = INT_MAX;
        while (en < nums.size())
        {
            int size = en - st + 1;

            if (size == maxWindow)
            {
                minSwaps = min(minSwaps, maxWindow - ones);
                ones -= (nums[st] == 1);
                st++;
            }
            else if (size < maxWindow)
            {
                en++;
                if (en == nums.size())
                {
                    break;
                }
                ones += (nums[en] == 1);
            }
            else
            {
                ones -= (nums[st] == 1);
                st++;
            }
        }

        return minSwaps;
    }
};