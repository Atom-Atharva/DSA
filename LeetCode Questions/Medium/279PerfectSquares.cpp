// https://leetcode.com/problems/perfect-squares/description/

#include <iostream>
using namespace std;
#include <climits>
#include <vector>

// Dynamic Programming
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int minSq = INT_MAX;
            for (int j = 1; j <= n; j++)
            {
                if (j * j > i)
                {
                    break;
                }
                int curr = 1 + dp[i - (j * j)];
                minSq = min(minSq, curr);
            }
            dp[i] = minSq == INT_MAX ? 0 : minSq;
        }

        return dp[n];
    }
};

// Recursive Approach + Memomization
class Solution
{
    int numSquares(int n, vector<int> &dp)
    {
        // Base Case
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // Find Closest Perfect Square
        int minSq = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            if (i * i > n)
            {
                break;
            }
            int curr = 1 + numSquares(n - (i * i), dp);
            minSq = min(minSq, curr);
        }

        return dp[n] = (minSq == INT_MAX) ? 0 : minSq;
    }

public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);

        return numSquares(n, dp);
    }
};