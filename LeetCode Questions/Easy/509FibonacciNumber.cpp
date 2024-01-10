// https://leetcode.com/problems/fibonacci-number/description/

#include <iostream>
using namespace std;
#include <vector>

// Space Optimization
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }

        int prev1 = 0;
        int prev2 = 1;

        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};

// Dynamic Programming
class Solution
{
public:
    int fib(int n)
    {
        // Base Case--
        if (n == 0 || n == 1)
        {
            return n;
        }

        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// Memomization Approach
class Solution
{
    int fib(int n, vector<int> &dp)
    {
        // Base Case--
        if (n == 0 || n == 1)
        {
            return n;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // Recursive Call--
        int nth = fib(n - 1, dp) + fib(n - 2, dp);

        return dp[n] = nth;
    }

public:
    int fib(int n)
    {
        vector<int> dp(n + 1, -1);
        return fib(n, dp);
    }
};

// Recursive Approach--
class Solution
{
public:
    int fib(int n)
    {
        // Base Case--
        if (n == 0 || n == 1)
        {
            return n;
        }

        // Recursive Call--
        int nth = fib(n - 1) + fib(n - 2);

        return nth;
    }
};