// https://www.geeksforgeeks.org/problems/rod-cutting0840/1

#include <iostream>
using namespace std;
#include <vector>

// Dynamic Programming
class Solution
{
public:
    int cutRod(int price[], int n)
    {
        vector<int> dp(n + 1, 0);

        for (int len = 1; len <= n; len++)
        {
            int value = 0;
            for (int i = 0; i < n; i++)
            {
                if (len - (i + 1) >= 0)
                {
                    value = max(value, dp[len - (i + 1)] + price[i]);
                }
            }

            dp[len] = value;
        }

        return dp[n];
    }
};

// Memomization
class Solution
{
    int cutRod(int price[], int n, int len, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (dp[len - 1] != -1)
        {
            return dp[len - 1];
        }

        int value = 0;
        for (int i = 0; i < n; i++)
        {
            if (len - (i + 1) >= 0)
            {
                value = max(value, cutRod(price, n, len - (i + 1), dp) + price[i]);
            }
        }

        return dp[len - 1] = value;
    }

public:
    int cutRod(int price[], int n)
    {
        vector<int> dp(n, -1);

        return cutRod(price, n, n, dp);
    }
};

// Recursive
class SolutionREC
{
    int cutRod(int price[], int n, int len)
    {
        if (n == 0)
        {
            return 0;
        }

        int value = 0;
        for (int i = 0; i < n; i++)
        {
            if (len - (i + 1) >= 0)
            {
                value = max(value, cutRod(price, n, len - (i + 1)) + price[i]);
            }
        }

        return value;
    }

public:
    int cutRod(int price[], int n)
    {
        return cutRod(price, n, n);
    }
};