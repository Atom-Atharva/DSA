// https://leetcode.com/problems/coin-change/description/

#include <iostream>
using namespace std;
#include <vector>
#include <climits>

// Dynamic Programming--
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            int minCount = INT_MAX;
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] < 0)
                {
                    continue;
                }
                int count = dp[i - coins[j]];
                if (count == -1)
                {
                    continue;
                }

                minCount = min(minCount, 1 + count);
            }
            dp[i] = (minCount == INT_MAX) ? -1 : minCount;
        }

        return dp[amount];
    }
};

// Memomization Approach--
class Solution
{
    int coinChange(vector<int> &coins, int amount, vector<int> &dp)
    {
        // Base Case--
        if (amount < 0)
        {
            return -1;
        }
        if (amount == 0)
        {
            return 0;
        }
        if (dp[amount] != -1)
        {
            return dp[amount];
        }

        // Recursive Calls--
        int minCount = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int count = coinChange(coins, amount - coins[i], dp);
            if (count == -1)
            {
                continue;
            }

            minCount = min(1 + count, minCount);
        }

        return dp[amount] = (minCount == INT_MAX) ? -1 : minCount;
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);
        return coinChange(coins, amount, dp);
    }
};

// Recursive Approach--
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // Base Case--
        if (amount < 0)
        {
            return -1;
        }
        if (amount == 0)
        {
            return 0;
        }

        // Recursive Calls--
        int minCount = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int count = coinChange(coins, amount - coins[i]);
            if (count == -1)
            {
                continue;
            }

            minCount = min(1 + count, minCount);
        }

        return (minCount == INT_MAX) ? -1 : minCount;
    }
};