// https://www.geeksforgeeks.org/problems/introduction-to-dp/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-dp

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
    long long int M = 1e9 + 7;

    long long int topDown(int n, vector<long long int> &memo)
    {
        if (n <= 1)
        {
            return n;
        }
        if (memo[n] != -1)
        {
            return memo[n];
        }

        return memo[n] = (topDown(n - 1, memo) + topDown(n - 2, memo)) % M;
    }

public:
    long long int topDown(int n)
    {
        vector<long long int> memo(n + 1, -1);
        return topDown(n, memo);
    }
    long long int bottomUp(int n)
    {
        vector<long long int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % M;
        }

        return dp[n];
    }
};