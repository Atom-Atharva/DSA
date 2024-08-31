// https://leetcode.com/problems/2-keys-keyboard/?envType=daily-question&envId=2024-08-19

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    int minSteps(int n, int len, int pas, vector<vector<int>> &dp)
    {
        // Base Case
        if (len > n)
        {
            return 1000000;
        }
        if (n == len)
        {
            return 0;
        }
        if (dp[len][pas] != -1)
        {
            return dp[len][pas];
        }

        // Copy and Paste
        int copy = minSteps(n, 2 * len, len, dp) + 2;
        if (pas == 0)
        {
            return dp[len][pas] = copy;
        }

        // Paste Only
        int paste = minSteps(n, len + pas, pas, dp) + 1;

        return dp[len][pas] = min(copy, paste);
    }

public:
    int minSteps(int n)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minSteps(n, 1, 0, dp);
    }
};