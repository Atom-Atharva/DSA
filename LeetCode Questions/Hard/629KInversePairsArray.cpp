// https://leetcode.com/problems/k-inverse-pairs-array/description/?envType=daily-question&envId=2024-01-27

#include <iostream>
using namespace std;
#include <vector>

// Recursive Approach
class Solution
{
    int M = 1e9 + 7;

    int kInversePairs(int n, int k, vector<vector<int>> &dp)
    {
        // Base Case
        if (n <= 0)
        {
            return 0;
        }
        if (k <= 0)
        {
            return k == 0;
        }
        if (dp[n][k] != -1)
        {
            return dp[n][k];
        }

        int ways = 0;
        for (int i = 0; i < n; i++)
        {
            ways += kInversePairs(n - 1, k - i, dp);
            ways %= M;
        }

        return dp[n][k] = ways;
    }

public:
    int kInversePairs(int n, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return kInversePairs(n, k, dp);
    }
};