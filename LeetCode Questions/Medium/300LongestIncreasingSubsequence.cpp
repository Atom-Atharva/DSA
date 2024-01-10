// https://leetcode.com/problems/longest-increasing-subsequence/?envType=daily-question&envId=2024-01-05

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

// Dynamic Approach--
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        // Dynamic Array--
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxElement = 1;
        for (int i = 0; i < dp.size(); i++)
        {
            maxElement = max(maxElement, dp[i]);
        }

        return maxElement;
    }
};

// Recursive Approach--
// class Solution
// {
//     int lengthLIS(vector<int> &nums, int pos, int prev, int len)
//     {
//         // Base Case--
//         if (pos == nums.size())
//         {
//             return len;
//         }

//         // Skip Current and Start New--
//         if (nums[pos] <= prev)
//         {
//             int skip = lengthLIS(nums, pos + 1, prev, len);
//             int start = lengthLIS(nums, pos + 1, INT_MIN, 0);

//             return max(skip, start);
//         }

//         // Skip or Take--
//         int skip = lengthLIS(nums, pos + 1, prev, len);
//         int take = lengthLIS(nums, pos + 1, nums[pos], len + 1);

//         return max(skip, take);
//     }

// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         return lengthLIS(nums, 0, INT_MIN, 0);
//     }
// };