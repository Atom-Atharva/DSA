// https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

#include <iostream>
using namespace std;
#include <vector>

// Optimize Solution
class Solution
{
    int M = 1e9 + 7;

public:
    long long countWays(int n, int k)
    {
        if (n == 1)
        {
            return k;
        }

        long long secondLast = k;
        long long last = (k + ((long long)k * (k - 1)) % M) % M;

        for (int i = 3; i <= n; i++)
        {
            long long curr = ((k - 1) * (last + secondLast) % M) % M;
            secondLast = last;
            last = curr;
        }

        return last;
    }
};

// Dynamic Programming
class Solution
{
    int M = 1e9 + 7;

public:
    long long countWays(int n, int k)
    {
        vector<long long> dp(n + 1, 0);
        dp[1] = k;
        dp[2] = (k + ((long long)k * (k - 1)) % M) % M;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2]) % M) % M;
        }

        return dp[n];
    }
};

// Memomization
class Solution
{
    int M = 1e9 + 7;
    long long countWays(int n, int k, vector<long long> &dp)
    {
        // Base Case--
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return k;
        }
        if (n == 2)
        {
            return (k + ((long long)k * (k - 1)) % M) % M;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // Recursive Calls--
        long long ans = ((k - 1) * (countWays(n - 1, k, dp) + countWays(n - 2, k, dp)) % M) % M;

        return dp[n] = ans;
    }

public:
    long long countWays(int n, int k)
    {
        vector<long long> dp(n + 1, -1);
        return countWays(n, k, dp);
    }
};

// Recursive Approach
class Solution
{
    int M = 1e9 + 7;

public:
    long long countWays(int n, int k)
    {
        // Base Case--
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return k;
        }
        if (n == 2)
        {
            return (k + (k * (k - 1)) % M) % M;
        }

        // Recursive Calls--
        long long ans = ((k - 1) * (countWays(n - 1, k) + countWays(n - 2, k)) % M) % M;

        return ans;
    }
};